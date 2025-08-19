//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_ILOAD_H
#define MYJVM8_ILOAD_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
void iload_(Frame& frame,int index){
  int value =frame.localVars_->getInt(index);
  frame.operandStack_->pushInt(value);
}
class Iload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    iload_(frame,index);
  }
};
class Iload_0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    iload_(frame,0);
  }
};
class Iload_1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    iload_(frame,1);
  }
};
class Iload_2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    iload_(frame,2);
  }
};
class Iload_3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    iload_(frame,3);
  }
};

#endif // MYJVM8_ILOAD_H
