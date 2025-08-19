//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef INVOKEVIRTUAL_HPP
#define INVOKEVIRTUAL_HPP

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../../rtda/heap/Constant.hpp"
#include "../../rtda/heap/ConstantPoolRun.hpp"

class Invokevirtual : public Instruction{
    void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
        int index=byte_code_reader.readU2();
        auto * constant_pool_run = frame.method->getClass().constantPoolRun;
        auto *constant=constant_pool_run->getConstant(index);
        auto *constantMethod=static_cast<ConstantMethod*>(constant);
        if(strcmp("println",constantMethod->getName()->data()) == 0) {
            auto stack = frame.operandStack_;
            auto descriptor = constantMethod->getDescriptor();
            switch (hash_compile_time(descriptor->data())) {
                case "(Z)V"_hash: {
                    printf("%d\n", stack->popInt() != 0);
                }
                case "(C)V"_hash "(I)V"_hash "(B)V"_hash "(S)V"_hash: {
                    printf("%d\n", stack->popInt());
                }
                case "(F)V"_hash: {
                    printf("%f\n", stack->popFloat());
                }
                case "(J)V"_hash: {
                    printf("%ld\n", stack->popLong());
                }
                case "(D)V"_hash: {
                    printf("%fd\n", stack->popDouble());
                }
                default: {
                    printf("%s\n", descriptor->data());
                }
            }
            stack->popDouble();
        }
    }
};


#endif //INVOKEVIRTUAL_HPP
