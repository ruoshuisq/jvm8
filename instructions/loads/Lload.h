//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_LLOAD_H
#define MYJVM8_LLOAD_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
void lload_(Frame& frame,int index){
  long value =frame.localVars_->getLong(index);
  frame.operandStack_->pushLong(value);
}
class Lload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    lload_(frame,index);
  }
};
class Lload_0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    lload_(frame,0);
  }
};
class Lload_1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    lload_(frame,1);
  }
};
class Lload_2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    lload_(frame,2);
  }
};
class Lload_3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    lload_(frame,3);
  }
};

#endif // MYJVM8_LLOAD_H
