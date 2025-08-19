//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_ISTORE_H
#define MYJVM8_ISTORE_H
#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
void istore_(Frame& frame,int index){
  int value =frame.operandStack_->popInt();
  frame.localVars_->setInt(index,value);
}
class Istore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    istore_(frame,index);
  }
};
class Istore_0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    istore_(frame,0);
  }
};
class Istore_1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    istore_(frame,1);
  }
};
class Istore_2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    istore_(frame,2);
  }
};
class Istore_3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    istore_(frame,3);
  }
};

#endif // MYJVM8_ISTORE_H
