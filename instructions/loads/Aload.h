//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_ALOAD_H
#define MYJVM8_ALOAD_H

#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

void aload_(Frame & frame,int index){
  Object *ref =frame.localVars_->getRef(index);
  frame.operandStack_->pushObject(*ref);
}
class Aload : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    aload_(frame,index);
  }
};
class Aload_0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    aload_(frame,0);
  }
};
class Aload_1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    aload_(frame,1);
  }
};
class Aload_2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    aload_(frame,2);
  }
};
class Aload_3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    aload_(frame,3);
  }
};
#endif // MYJVM8_ALOAD_H
