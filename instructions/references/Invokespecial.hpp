//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef INVOKESPECIAL_HPP
#define INVOKESPECIAL_HPP

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"

class Invokespecial : public Instruction{
    void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
        int index=byte_code_reader.readU2();
        // hack!
        frame.operandStack_->popObject();
    }
};


#endif //INVOKESPECIAL_HPP
