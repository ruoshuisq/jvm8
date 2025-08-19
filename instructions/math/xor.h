//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_XOR_H
#define MYJVM8_XOR_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
class Ixor : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int val1 =frame.operandStack_->popInt();
    int val2=frame.operandStack_->popInt();
    int val3=val1 ^ val2;
    frame.operandStack_->pushInt(val3);
  }
};
class Lxor : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long val1 =frame.operandStack_->popLong();
    long val2=frame.operandStack_->popLong();
    long val3=val1 ^ val2;
    frame.operandStack_->pushLong(val3);
  }
};

#endif // MYJVM8_XOR_H
