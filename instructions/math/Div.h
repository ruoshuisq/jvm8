//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_DIV_H
#define MYJVM8_DIV_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
class Idiv : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int val1 =frame.operandStack_->popInt();
    int val2=frame.operandStack_->popInt();
    if (val2 == 0) {
        printf("java.lang.ArithmeticException: / by zero");//TODO有问题
      }
    int val3=val1 / val2;

    frame.operandStack_->pushInt(val3);
  }
};
class Ldiv : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long val1 =frame.operandStack_->popLong();
    long val2=frame.operandStack_->popLong();
    if (val2 == 0) {
      printf("java.lang.ArithmeticException: / by zero");//TODO有问题
    }
    long val3=val1 / val2;
    frame.operandStack_->pushLong(val3);
  }
};
class Fdiv : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    float val1 =frame.operandStack_->popFloat();
    float val2=frame.operandStack_->popFloat();
    float val3=val1/val2;
    frame.operandStack_->pushFloat(val3);
  }
};
class Ddiv : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    double val1 =frame.operandStack_->popDouble();
    double val2=frame.operandStack_->popDouble();
    double val3=val1/val2;
    frame.operandStack_->pushDouble(val3);
  }
};

#endif // MYJVM8_DIV_H
