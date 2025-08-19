//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef GETSTATIC_HPP
#define GETSTATIC_HPP

#include "../rtda/heap/JClass.hpp"
#include "../rtda/heap/Constant.hpp"
#include "../rtda/heap/ConstantPoolRun.hpp"
#include "../rtda/heap/Method.hpp"
#include "../rtda/heap/Object.h"
#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../../rtda/heap/Field.hpp"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

// getstatic指令将类的某个静态变量放入栈顶
class Getstatic : public Instruction{
    // 将类的某个静态变量放入栈顶
    void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
        int index=byte_code_reader.readU2();
        Method * method = frame.method;
        JClass currentClass = method->getClass();
        ConstantPoolRun * constant_pool_run = currentClass.constantPoolRun;
        Constant * constant = constant_pool_run->getConstant(index);
        ConstantField *constantField=static_cast<ConstantField*>(constant);
        constantField->resolvedField();
        Field * field = constantField->field;
        JClass fieldClass = field->getClass();
        if (!field->isStatic()) {
            printf("java.lang.IncompatibleClassChangeError");//TODO退出未实现
        }

        int slot_id = field->getSlotId();
        std::map<int, Solt> staticVars=*fieldClass.staticVars;
        OperandStack * stack = frame.operandStack_;
        std::string descriptor = field->descriptor;
        switch (hash_compile_time(descriptor.data())) {
            case "Z"_hash "B"_hash "C"_hash "S"_hash "I"_hash: {
                stack->pushInt(staticVars[slot_id].byte4Int);
            }
            case "J"_hash: {
                stack->pushLong(staticVars[slot_id].byte8Long);
            }
            case "F"_hash: {
                stack->pushFloat(staticVars[slot_id].byte4Float);
            }
            case "D"_hash: {
                stack->pushDouble(staticVars[slot_id].byte8Double);
            }
            default: {
                stack->pushObject(*staticVars[slot_id].ref);
            }
        }
    }
};




#endif //GETSTATIC_HPP
