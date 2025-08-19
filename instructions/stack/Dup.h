//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_DUP_H
#define MYJVM8_DUP_H

#include "../rtda/heap/JClass.hpp"
#include "../rtda/heap/Constant.hpp"
#include "../rtda/heap/ConstantPoolRun.hpp"
#include "../rtda/heap/Method.hpp"
#include "../rtda/heap/Object.h"
#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

class Dup : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Solt solt =frame.operandStack_->popSolt();
    frame.operandStack_->pushSolt(solt);
    frame.operandStack_->pushSolt(solt);
  }
};
class Dupx1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Solt solt1 =frame.operandStack_->popSolt();
    Solt solt2 =frame.operandStack_->popSolt();
    frame.operandStack_->pushSolt(solt1);
    frame.operandStack_->pushSolt(solt2);
    frame.operandStack_->pushSolt(solt1);
  }
};
class Dupx2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Solt solt1 =frame.operandStack_->popSolt();
    Solt solt2 =frame.operandStack_->popSolt();
    Solt solt3 =frame.operandStack_->popSolt();
    frame.operandStack_->pushSolt(solt1);
    frame.operandStack_->pushSolt(solt3);
    frame.operandStack_->pushSolt(solt2);
    frame.operandStack_->pushSolt(solt1);
  }
};
class Dup2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Solt solt1 =frame.operandStack_->popSolt();
    Solt solt2 =frame.operandStack_->popSolt();
    frame.operandStack_->pushSolt(solt2);
    frame.operandStack_->pushSolt(solt1);
    frame.operandStack_->pushSolt(solt2);
    frame.operandStack_->pushSolt(solt1);
  }
};
class Dup2x1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Solt solt1 =frame.operandStack_->popSolt();
    Solt solt2 =frame.operandStack_->popSolt();
    Solt solt3 =frame.operandStack_->popSolt();
    frame.operandStack_->pushSolt(solt2);
    frame.operandStack_->pushSolt(solt1);
    frame.operandStack_->pushSolt(solt3);
    frame.operandStack_->pushSolt(solt2);
    frame.operandStack_->pushSolt(solt1);
  }
};
class Dup2x2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    Solt solt1 =frame.operandStack_->popSolt();
    Solt solt2 =frame.operandStack_->popSolt();
    Solt solt3 =frame.operandStack_->popSolt();
    Solt solt4 =frame.operandStack_->popSolt();
    frame.operandStack_->pushSolt(solt2);
    frame.operandStack_->pushSolt(solt1);
    frame.operandStack_->pushSolt(solt4);
    frame.operandStack_->pushSolt(solt3);
    frame.operandStack_->pushSolt(solt2);
    frame.operandStack_->pushSolt(solt1);
  }
};
#endif // MYJVM8_DUP_H
