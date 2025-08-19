//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef PUTFIELD_HPP
#define PUTFIELD_HPP

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

// putfield cpindex val objref，它需要三个操作数。
// 前两个操作数是常量池索引和变量值，用法和putstatic一样。第三个操作数是对象引用，从操作数栈中弹出
class Putfield : public Instruction{
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
        if (field->isStatic()) {
            printf("java.lang.IncompatibleClassChangeError");//TODO退出未实现
        }
        if (field->isFinal()) {
            if (currentClass != fieldClass || method->getName() != "<clinit>") {
                printf("java.lang.IllegalAccessError");//TODO退出未实现
            }
        }
        int slot_id = field->getSlotId();
        OperandStack * stack = frame.operandStack_;
        std::string descriptor = field->descriptor;
        switch (hash_compile_time(descriptor.data())) {
            case "Z"_hash "B"_hash "C"_hash "S"_hash "I"_hash: {
                int val = stack->popInt();
                Object * ref = stack->popObject();
                if(ref==nullptr) {
                    printf("");//TODO退出未实现
                }
                auto pairs = *ref->fields;
                pairs[slot_id].byte4Int=val;
            }
            case "J"_hash: {
                long val = stack->popLong();
                Object * ref = stack->popObject();
                if(ref==nullptr) {
                    printf("");//TODO退出未实现
                }
                auto pairs = *ref->fields;
                pairs[slot_id].byte8Long=val;
            }
            case "F"_hash: {
                float val = stack->popFloat();
                Object * ref = stack->popObject();
                if(ref==nullptr) {
                    printf("");//TODO退出未实现
                }
                auto pairs = *ref->fields;
                pairs[slot_id].byte4Float=val;
            }
            case "D"_hash: {
                double val = stack->popDouble();
                Object * ref = stack->popObject();
                if(ref==nullptr) {
                    printf("");//TODO退出未实现
                }
                auto pairs = *ref->fields;
                pairs[slot_id].byte8Double=val;
            }
            default: {
                Object * val = stack->popObject();
                Object * ref = stack->popObject();
                if(ref==nullptr) {
                    printf("");//TODO退出未实现
                }
                auto pairs = *ref->fields;
                pairs[slot_id].ref=val;
            }
        }
    }
};



#endif //PUTFIELD_HPP
