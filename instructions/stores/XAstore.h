//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_XASTORE_H
#define MYJVM8_XASTORE_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
class AAstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Object *val =frame.operandStack_->popObject();
    int index=frame.operandStack_->popInt();
    Object *arrayRef =frame.operandStack_->popObject();
    arrayRef[index]=*val;
  }
};
class BAstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Object *val =frame.operandStack_->popObject();
    int index=frame.operandStack_->popInt();
    Object *arrayRef =frame.operandStack_->popObject();
    arrayRef[index]=*val;//TODO有问题
  }
};
class CAstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Object *val =frame.operandStack_->popObject();
    int index=frame.operandStack_->popInt();
    Object *arrayRef =frame.operandStack_->popObject();
    arrayRef[index]=*val;//TODO有问题
  }
};
class DAstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Object *val =frame.operandStack_->popObject();
    int index=frame.operandStack_->popInt();
    Object *arrayRef =frame.operandStack_->popObject();
    arrayRef[index]=*val;//TODO有问题
  }
};
class FAstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Object *val =frame.operandStack_->popObject();
    int index=frame.operandStack_->popInt();
    Object *arrayRef =frame.operandStack_->popObject();
    arrayRef[index]=*val;//TODO有问题
  }
};
class IAstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Object *val =frame.operandStack_->popObject();
    int index=frame.operandStack_->popInt();
    Object *arrayRef =frame.operandStack_->popObject();
    arrayRef[index]=*val;//TODO有问题
  }
};
class LAstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Object *val =frame.operandStack_->popObject();
    int index=frame.operandStack_->popInt();
    Object *arrayRef =frame.operandStack_->popObject();
    arrayRef[index]=*val;//TODO有问题
  }
};
class SAstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Object *val =frame.operandStack_->popObject();
    int index=frame.operandStack_->popInt();
    Object *arrayRef =frame.operandStack_->popObject();
    arrayRef[index]=*val;//TODO有问题
  }
};
#endif // MYJVM8_XASTORE_H
