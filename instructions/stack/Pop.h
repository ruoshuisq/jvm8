//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_POP_H
#define MYJVM8_POP_H

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

class Pop : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->popSolt();
  }
};
class Pop2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    frame.operandStack_->popSolt();
    frame.operandStack_->popSolt();
  }
};
#endif // MYJVM8_POP_H
