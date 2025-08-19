//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_DSTORE_H
#define MYJVM8_DSTORE_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
void dstore_(Frame &frame,int index){
  float value =frame.operandStack_->popFloat();
  frame.localVars_->setFloat(index,value);
}
class Dstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    dstore_(frame,index);
  }
};
class Dstore_0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    dstore_(frame,0);
  }
};
class Dstore_1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    dstore_(frame,1);
  }
};
class Dstore_2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    dstore_(frame,2);
  }
};
class Dstore_3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    dstore_(frame,3);
  }
};

#endif // MYJVM8_DSTORE_H
