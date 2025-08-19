//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_DCMG_H
#define MYJVM8_DCMG_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Frame.h"
#include "../rtda/Solt.hpp"

class Lcmp : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long v1 =frame.operandStack_->popLong();
    long v2 =frame.operandStack_->popLong();
    if (v1 > v2) {
      frame.operandStack_->pushInt(1);
    } else if (v1 == v2) {
      frame.operandStack_->pushInt(0);
    } else {
      frame.operandStack_->pushInt(-1);
    }
  }
};

#endif // MYJVM8_DCMG_H
