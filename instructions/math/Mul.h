//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_MUL_H
#define MYJVM8_MUL_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
class Imul : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int val1 =frame.operandStack_->popInt();
    int val2=frame.operandStack_->popInt();
    int val3=val1*val2;
    frame.operandStack_->pushInt(val3);
  }
};
class Lmul : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long val1 =frame.operandStack_->popLong();
    long val2=frame.operandStack_->popLong();
    long val3=val1*val2;
    frame.operandStack_->pushLong(val3);
  }
};
class Fmul : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    float val1 =frame.operandStack_->popFloat();
    float val2=frame.operandStack_->popFloat();
    float val3=val1*val2;
    frame.operandStack_->pushFloat(val3);
  }
};
class Dmul : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    double val1 =frame.operandStack_->popDouble();
    double val2=frame.operandStack_->popDouble();
    double val3=val1*val2;
    frame.operandStack_->pushDouble(val3);
  }
};

#endif // MYJVM8_MUL_H
