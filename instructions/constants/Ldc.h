//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_LDC_H
#define MYJVM8_LDC_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/heap/JClass.hpp"
#include "../rtda/heap/Constant.hpp"
#include "../rtda/heap/ConstantPoolRun.hpp"
#include "../rtda/heap/Method.hpp"
#include "../rtda/heap/Object.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

void _ldc(Frame & frame, int index) {
  ConstantPoolRun * constant_pool_run = frame.method->getClass().constantPoolRun;
  OperandStack * stack = frame.operandStack_;
  Constant * constant = constant_pool_run->getConstant(index);
  switch (constant->type) {
    case CONSTANT_Integer: {
      ConstantInteger *constantInteger=static_cast<ConstantInteger*>(constant);
      stack->pushInt(constantInteger->getValue());
      break;
    }
    case CONSTANT_Float: {
      ConstantFloat *constantFloat=static_cast<ConstantFloat*>(constant);
      stack->pushFloat(constantFloat->getValue());
      break;
    }default: {
      //todo
    }
  }
}

class Ldc : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = byte_code_reader.readU1();
    _ldc(frame,index);
  }
};
class Ldc_w : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = byte_code_reader.readU2();
    _ldc(frame,index);
  }
};
class Ldc2_w : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index = byte_code_reader.readU2();
    ConstantPoolRun * constant_pool_run = frame.method->getClass().constantPoolRun;
    OperandStack * stack = frame.operandStack_;
    Constant * constant = constant_pool_run->getConstant(index);
    switch (constant->type) {
      case CONSTANT_Long: {
        ConstantLong *constantLong=static_cast<ConstantLong*>(constant);
        stack->pushLong(constantLong->getValue());
        break;
      }
      case CONSTANT_Double: {
        ConstantDouble *constantDouble=static_cast<ConstantDouble*>(constant);
        stack->pushDouble(constantDouble->getValue());
        break;
      }default: {
        //todo
      }
    }
  }
};
#endif // MYJVM8_LDC_H
