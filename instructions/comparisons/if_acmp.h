//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_IF_ACMP_H
#define MYJVM8_IF_ACMP_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Frame.h"
#include "../rtda/Solt.hpp"

// if v1 == v2
class If_acmpeq : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    Object *v1 =frame.operandStack_->popObject();
    Object *v2 =frame.operandStack_->popObject();
    if (v1 == v2 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};

// if v1 != v2
class If_acmpne : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    Object *v1 =frame.operandStack_->popObject();
    Object *v2 =frame.operandStack_->popObject();
    if (v1 != v2 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};

#endif // MYJVM8_IF_ACMP_H
