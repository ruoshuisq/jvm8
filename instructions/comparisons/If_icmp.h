//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_IF_ICMP_H
#define MYJVM8_IF_ICMP_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Frame.h"
#include "../rtda/Solt.hpp"

// if v1 == v2
class If_icmpeq : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v2 =frame.operandStack_->popInt();
    int v1 =frame.operandStack_->popInt();
    if (v1 ==v2 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
// if v1 != v2
class If_icmpne : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v2 =frame.operandStack_->popInt();
    int v1 =frame.operandStack_->popInt();
    if (v1 !=v2 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
// if v1 < v2
class If_icmplt : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v2 =frame.operandStack_->popInt();
    int v1 =frame.operandStack_->popInt();
    if (v1 < v2 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
// if v1 <= v2
class If_icmple : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v2 =frame.operandStack_->popInt();
    int v1 =frame.operandStack_->popInt();
    if (v1 <= v2 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
// if v1 > v2
class If_icmpgt : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v2 =frame.operandStack_->popInt();
    int v1 =frame.operandStack_->popInt();
    if (v1 > v2 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
// if v1 >= v2
class If_icmpge : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    int v2 =frame.operandStack_->popInt();
    int v1 =frame.operandStack_->popInt();
    if (v1 >= v2 ) {
      go_to(frame, offset, byte_code_reader);
    }
  }
};
#endif // MYJVM8_IF_ICMP_H
