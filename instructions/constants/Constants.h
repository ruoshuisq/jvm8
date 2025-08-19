//
// Created by zj on 2025/7/25.
//

#ifndef ConstANTS_H
#define ConstANTS_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Frame.h"
#include "../rtda/Solt.hpp"

class Nop : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    // really do nothing
  }
};
class IConstM1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushInt(-1);
  }
};
class IConst0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushInt(0);
  }
};
class IConst1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushInt(1);
  }
};
class IConst2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushInt(2);
  }
};
class IConst3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushInt(3);
  }
};
class IConst4 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushInt(4);
  }
};
class IConst5 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushInt(5);
  }
};
class AConstNULL : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
//    frame.operandStack_->pushObject(&nullptr);
  }
};
class LConst0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushLong(0);
  }
};
class LConst1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushLong(1);
  }
};
class FConst0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushFloat(0);
  }
};
class FConst1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushFloat(1);
  }
};
class FConst2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushFloat(2);
  }
};
class DConst0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushDouble(0);
  }
};
class DConst1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->pushDouble(1);
  }
};
#endif //ConstANTS_H
