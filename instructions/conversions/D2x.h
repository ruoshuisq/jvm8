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

class D2i : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    double val =frame.operandStack_->popDouble();
    int val2=(int)val;
    frame.operandStack_->pushInt(val2);
  }
};
class D2f : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    double val =frame.operandStack_->popDouble();
    float val2=static_cast<float>(val);
    frame.operandStack_->pushFloat(val2);
  }
};
class D2l : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    double val =frame.operandStack_->popDouble();
    long val2=(long)val;
    frame.operandStack_->pushLong(val2);
  }
};
#endif // MYJVM8_D2X_H
