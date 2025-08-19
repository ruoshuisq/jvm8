//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_LSTORE_H
#define MYJVM8_LSTORE_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
void lstore_(Frame& frame,int index){
  long value =frame.operandStack_->popLong();
  frame.localVars_->setLong(index,value);
}
class Lstore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    lstore_(frame,index);
  }
};
class Lstore_0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    lstore_(frame,0);
  }
};
class Lstore_1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    lstore_(frame,1);
  }
};
class Lstore_2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    lstore_(frame,2);
  }
};
class Lstore_3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    lstore_(frame,3);
  }
};

#endif // MYJVM8_LSTORE_H
