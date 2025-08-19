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

class Goto_w : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    u4 offset=byte_code_reader.readU4();
    go_to(frame, offset, byte_code_reader);
  }
};
#endif // MYJVM8_GOTO_W_H
