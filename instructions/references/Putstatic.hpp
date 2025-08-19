//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef PUTSTATIC_HPP
#define PUTSTATIC_HPP

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

// putstatic指令给类的某个静态变量赋值，它需要两个操作数。一个字段符号引用，一个从操作数栈弹出
class Putstatic : public Instruction{
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
        JClass fieldClass = field->getClass();
        if (!field->isStatic()) {
            printf("java.lang.IncompatibleClassChangeError");//TODO退出未实现
        }
        if (field->isFinal()) {
            if (currentClass != fieldClass || method->getName() != "<clinit>") {
                printf("java.lang.IllegalAccessError");//TODO退出未实现
            }
        }
        int slot_id = field->getSlotId();
        std::map<int, Solt> staticVars=*fieldClass.staticVars;
        OperandStack * stack = frame.operandStack_;
        std::string descriptor = field->descriptor;
        switch (hash_compile_time(descriptor.data())) {
            case "Z"_hash "B"_hash "C"_hash "S"_hash "I"_hash: {
                staticVars[slot_id].byte4Int=stack->popInt();
            }
            case "J"_hash: {
               staticVars[slot_id].byte8Long=stack->popLong();
            }
            case "F"_hash: {
                staticVars[slot_id].byte4Float=stack->popFloat();
            }
            case "D"_hash: {
                staticVars[slot_id].byte8Double=stack->popDouble();
            }
            default: {
                staticVars[slot_id].ref=stack->popObject();
            }
        }
    }
};



#endif //PUTSTATIC_HPP
