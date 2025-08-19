//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_NEG_H
#define MYJVM8_NEG_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
class Ineg : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int val =frame.operandStack_->popInt();
    frame.operandStack_->pushInt(-val);
  }
};
class Lneg : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long val =frame.operandStack_->popLong();
    frame.operandStack_->pushLong(-val);
  }
};
class Fneg : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    float val =frame.operandStack_->popFloat();
    frame.operandStack_->pushFloat(-val);
  }
};
class Dneg : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    double val =frame.operandStack_->popDouble();
    frame.operandStack_->pushDouble(-val);
  }
};

#endif // MYJVM8_NEG_H
