//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_RETURN_H
#define MYJVM8_RETURN_H

#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

class Return : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.thread->popFrame();
  }
};

class AReturn : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Frame *currentFrame = frame.thread->popFrame();
    Frame *invokerFrame = frame.thread->topFrame();
    Object *val=currentFrame->operandStack_->popObject();
    invokerFrame->operandStack_->pushObject(*val);
  }
};
class DReturn : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Frame *currentFrame = frame.thread->popFrame();
    Frame *invokerFrame = frame.thread->topFrame();
    double val=currentFrame->operandStack_->popDouble();
    invokerFrame->operandStack_->pushDouble(val);
  }
};
class FReturn : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Frame *currentFrame = frame.thread->popFrame();
    Frame *invokerFrame = frame.thread->topFrame();
    float val=currentFrame->operandStack_->popFloat();
    invokerFrame->operandStack_->pushFloat(val);
  }
};
class IReturn : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Frame *currentFrame = frame.thread->popFrame();
    Frame *invokerFrame = frame.thread->topFrame();
    int val=currentFrame->operandStack_->popInt();
    invokerFrame->operandStack_->pushInt(val);
  }
};
class LReturn : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Frame *currentFrame = frame.thread->popFrame();
    Frame *invokerFrame = frame.thread->topFrame();
    long val=currentFrame->operandStack_->popLong();
    invokerFrame->operandStack_->pushLong(val);
  }
};
#endif // MYJVM8_RETURN_H
