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

class F2i : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    float val =frame.operandStack_->popFloat();
    int val2=(int)val;
    frame.operandStack_->pushInt(val2);
  }
};
class F2d : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    float val =frame.operandStack_->popFloat();
    double val2=(double )val;
    frame.operandStack_->pushDouble(val2);
  }
};
class F2l : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    float val =frame.operandStack_->popFloat();
    long val2=(long)val;
    frame.operandStack_->pushLong(val2);
  }
};
#endif // MYJVM8_D2X_H
