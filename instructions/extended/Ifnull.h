//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_GOTO_W_H
#define MYJVM8_GOTO_W_H

#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

class Ifnull : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    Object *ref=frame.operandStack_->popObject();
    if(ref== nullptr){//TODO有问题
      go_to(frame, offset, byte_code_reader);
    }
  }
};
class Ifnonull : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    s2 offset=byte_code_reader.readS2();
    Object *ref=frame.operandStack_->popObject();
    if(ref!= nullptr){//TODO有问题
      go_to(frame, offset, byte_code_reader);
    }
  }
};
#endif // MYJVM8_GOTO_W_H
