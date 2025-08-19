//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_D2X_H
#define MYJVM8_D2X_H

#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

class L2f : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long val =frame.operandStack_->popLong();
    float val2=(float)val;
    frame.operandStack_->pushFloat(val2);
  }
};
class L2d : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long val =frame.operandStack_->popLong();
    double val2=(double )val;
    frame.operandStack_->pushDouble(val2);
  }
};
class L2i : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long val =frame.operandStack_->popLong();
    int val2=(long)val;
    frame.operandStack_->pushInt(val2);
  }
};
#endif // MYJVM8_D2X_H
