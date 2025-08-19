//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_FLOAD_H
#define MYJVM8_FLOAD_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
void fload_(Frame & frame,int index){
  float value =frame.localVars_->getFloat(index);
  frame.operandStack_->pushFloat(value);
}
class Fload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    fload_(frame,index);
  }
};
class Fload_0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    fload_(frame,0);
  }
};
class Fload_1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    fload_(frame,1);
  }
};
class Fload_2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    fload_(frame,2);
  }
};
class Fload_3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    fload_(frame,3);
  }
};


#endif // MYJVM8_FLOAD_H
