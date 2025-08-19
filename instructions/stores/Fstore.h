//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_FSTORE_H
#define MYJVM8_FSTORE_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
void fstore_(Frame& frame,int index){
  float value =frame.operandStack_->popFloat();
  frame.localVars_->setFloat(index,value);
}
class Fstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    fstore_(frame,index);
  }
};
class Fstore_0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    fstore_(frame,0);
  }
};
class Fstore_1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    fstore_(frame,1);
  }
};
class Fstore_2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    fstore_(frame,2);
  }
};
class Fstore_3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    fstore_(frame,3);
  }
};

#endif // MYJVM8_FSTORE_H
