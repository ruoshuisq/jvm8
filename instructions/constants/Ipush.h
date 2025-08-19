//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_IPUSH_H
#define MYJVM8_IPUSH_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Frame.h"
#include "../rtda/Solt.hpp"

class Bipush : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int bInt=byte_code_reader.readU1();
    frame.operandStack_->pushInt(bInt);
  }
};
class Sipush : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int bInt=byte_code_reader.readU2();
    frame.operandStack_->pushInt(bInt);
  }
};

#endif // MYJVM8_IPUSH_H
