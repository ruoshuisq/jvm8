//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef GETFIELD_HPP
#define GETFIELD_HPP

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

class Getfield : public Instruction{
    // 从栈顶取出变量值，然后给类的静态变量赋值
    void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
        int index=byte_code_reader.readU2();
        Method * method = frame.method;
        JClass currentClass = method->getClass();
        ConstantPoolRun * constant_pool_run = currentClass.constantPoolRun;
        Constant * constant = constant_pool_run->getConstant(index);
        ConstantField *constantField=static_cast<ConstantField*>(constant);
        constantField->resolvedField();
        Field * field = constantField->field;
        if (field->isStatic()) {
            printf("java.lang.IncompatibleClassChangeError");//TODO退出未实现
        }
        OperandStack * stack = frame.operandStack_;
        Object * ref = stack->popObject();
        if (ref == nullptr) {
            printf("java.lang.NullPointerException");//TODO退出未实现
        }
        int slot_id = field->getSlotId();
        std::string descriptor = field->descriptor;
        std::map<int, Solt> fields=* ref->fields;
        switch (hash_compile_time(descriptor.data())) {
            case "Z"_hash "B"_hash "C"_hash "S"_hash "I"_hash: {
                stack->pushInt(fields[slot_id].byte4Int);
            }
            case "J"_hash: {
                stack->pushLong(fields[slot_id].byte8Long);
            }
            case "F"_hash: {
                stack->pushFloat(fields[slot_id].byte4Float);
            }
            case "D"_hash: {
                stack->pushDouble(fields[slot_id].byte8Double);
            }
            default: {
                stack->pushObject(*fields[slot_id].ref);
            }
        }
    }
};


#endif //GETFIELD_HPP
