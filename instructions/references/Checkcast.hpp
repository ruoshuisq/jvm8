//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef CHECKCAST_HPP
#define CHECKCAST_HPP

#include "../rtda/heap/JClass.hpp"
#include "../rtda/heap/Constant.hpp"
#include "../rtda/heap/ConstantPoolRun.hpp"
#include "../rtda/heap/Method.hpp"
#include "../rtda/heap/Object.h"
#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

// Check whether object is of given type
// Checkcast do not change operand stack
class Checkcast : public Instruction{
    void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
        int index=byte_code_reader.readU2();
        OperandStack * stack = frame.operandStack_;
        Object * ref = stack->popObject();
        if(ref==nullptr) {
            stack->pushInt(0);
            return;
        }
        ConstantPoolRun * constant_pool_run = frame.method->getClass().constantPoolRun;
        Constant * constant = constant_pool_run->getConstant(index);
        ConstantClass *constantClass=static_cast<ConstantClass*>(constant);
        constantClass->resolvedClass();
        JClass jClass = *constantClass->jClass;
        if(!ref->isInstanceOf(jClass)) {
            printf("java.lang.ClassCastException");
        }
    }
};

#endif //CHECKCAST_HPP
