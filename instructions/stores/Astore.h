//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_ASTORE_H
#define MYJVM8_ASTORE_H

#include "../rtda/heap/JClass.hpp"
#include "../rtda/heap/Constant.hpp"
#include "../rtda/heap/ConstantPoolRun.hpp"
#include "../rtda/heap/Method.hpp"
#include "../rtda/heap/Object.h"
#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

void astore_(Frame& frame,int index){
  Object *ref =frame.operandStack_->popObject();
  frame.localVars_->setRef(index,*ref);
}
class Astore : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    astore_(frame,index);
  }
};
class Astore_0 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    astore_(frame,0);
  }
};
class Astore_1 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    astore_(frame,1);
  }
};
class Astore_2 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    astore_(frame,2);
  }
};
class Astore_3 : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    astore_(frame,3);
  }
};
#endif // MYJVM8_ASTORE_H
