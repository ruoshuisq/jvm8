//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_XALOAD_H
#define MYJVM8_XALOAD_H
#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
class AAload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = frame.operandStack_->popInt();
    Object *ref = frame.operandStack_->popObject();
    frame.operandStack_->pushObject(ref[index]);//TODO可能有问题
  }
};
class BAload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = frame.operandStack_->popInt();
    Object *ref = frame.operandStack_->popObject();
    frame.operandStack_->pushObject(ref[index]);//TODO有问题
  }
};
class CAload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = frame.operandStack_->popInt();
    Object *ref = frame.operandStack_->popObject();
    frame.operandStack_->pushObject(ref[index]);//TODO有问题
  }
};
class DAload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = frame.operandStack_->popInt();
    Object *ref = frame.operandStack_->popObject();
    frame.operandStack_->pushObject(ref[index]);//TODO有问题
  }
};
class FAload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = frame.operandStack_->popInt();
    Object *ref = frame.operandStack_->popObject();
    frame.operandStack_->pushObject(ref[index]);//TODO有问题
  }
};
class IAload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = frame.operandStack_->popInt();
    Object *ref = frame.operandStack_->popObject();
    frame.operandStack_->pushObject(ref[index]);//TODO有问题
  }
};
class LAload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = frame.operandStack_->popInt();
    Object *ref = frame.operandStack_->popObject();
    frame.operandStack_->pushObject(ref[index]);//TODO有问题
  }
};
class SAload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = frame.operandStack_->popInt();
    Object *ref = frame.operandStack_->popObject();
    frame.operandStack_->pushObject(ref[index]);//TODO有问题
  }
};
#endif // MYJVM8_XALOAD_H
