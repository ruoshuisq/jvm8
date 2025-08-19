//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_IFCOND_H
#define MYJVM8_IFCOND_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Frame.h"
#include "../rtda/Solt.hpp"

// if x == 0
class Ifeq : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v1 =frame.operandStack_->popInt();
    if (v1 ==0 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
// if x != 0
class Ifne : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v1 =frame.operandStack_->popInt();
    if (v1 !=0 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
// if x < 0
class Iflt : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v1 =frame.operandStack_->popInt();
    if (v1 <0 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
// if x <= 0
class Ifle : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v1 =frame.operandStack_->popInt();
    if (v1 <=0 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};

// if x > 0
class Ifgt : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v1 =frame.operandStack_->popInt();
    if (v1 >0 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
// if x >= 0
class Ifge : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v1 =frame.operandStack_->popInt();
    if (v1 >=0 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
#endif // MYJVM8_IFCOND_H
