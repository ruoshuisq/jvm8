//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_SH_H
#define MYJVM8_SH_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
//将int左移指定位数，并将结果压入操作数栈
class Ishl : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int move =frame.operandStack_->popInt();
    int val=frame.operandStack_->popInt();
    int val3=val << move;
    frame.operandStack_->pushInt(val3);
  }
};
//将long左移指定位数，并将结果压入操作数栈
class Lshl : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long move =frame.operandStack_->popLong();
    long val=frame.operandStack_->popLong();
    long val3=val << move;
    frame.operandStack_->pushLong(val3);
  }
};
//将int右移指定位数，并将结果压入操作数栈
class Ishr : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int move =frame.operandStack_->popInt();
    int val=frame.operandStack_->popInt();
    int val3=val >> move;
    frame.operandStack_->pushInt(val3);
  }
};
//将long右移指定位数，并将结果压入操作数栈
class Lshr : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    long move =frame.operandStack_->popLong();
    long val=frame.operandStack_->popLong();
    long val3=val >> move;
    frame.operandStack_->pushLong(val3);
  }
};
//将int右移(无符号)指定位数，并将结果压入操作数栈
class Iushr : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    unsigned int move =frame.operandStack_->popInt();
    unsigned int val=frame.operandStack_->popInt();
    unsigned int val3=val >> move;
    frame.operandStack_->pushInt(val3);
  }
};
//将long右移(无符号)指定位数，并将结果压入操作数栈
class Lushr : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    unsigned long move =frame.operandStack_->popLong();
    unsigned long val=frame.operandStack_->popLong();
    unsigned long val3=val >> move;
    frame.operandStack_->pushLong(val3);
  }
};
#endif // MYJVM8_SH_H
