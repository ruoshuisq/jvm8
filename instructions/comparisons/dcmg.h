//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_DCMG_H
#define MYJVM8_DCMG_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Frame.h"
#include "../rtda/Solt.hpp"
void dcmp_(Frame &frame,bool gFlag){
  double v2 =frame.operandStack_->popDouble();
  double v1 =frame.operandStack_->popDouble();
  if (v1 > v2) {
    frame.operandStack_->pushInt(1);
    } else if (v1 == v2) {
      frame.operandStack_->pushInt(0);
    } else if (v1 < v2) {
      frame.operandStack_->pushInt(-1);
    } else if (gFlag) {
      frame.operandStack_->pushInt(1);
  } else {
    frame.operandStack_->pushInt(-1);
  }
}
// when num(NaN) >= 1, then push 1
class Dcmpg : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    dcmp_(frame, true);
  }
};
// when num(NaN) >= 1, then push -1
class Dcmpl : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    dcmp_(frame, false);
  }
};

#endif // MYJVM8_DCMG_H
