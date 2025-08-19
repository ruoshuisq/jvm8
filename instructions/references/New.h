//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_NEW_H
#define MYJVM8_NEW_H

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

class New : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU2();
    ConstantPoolRun * constant_pool_run = frame.method->getClass().constantPoolRun;
    Constant * constant = constant_pool_run->getConstant(index);
    ConstantClass *constantClass=static_cast<ConstantClass*>(constant);
    constantClass->resolvedClass();
    JClass jClass =*constantClass->jClass;
    if(jClass.isAbstract() ||jClass.isInterface()) {
      printf("java.lang.InstantiationError");//TODO退出未实现
    }
    Object object=jClass.newObject(jClass);
    frame.operandStack_->pushObject(object);

  }
};

#endif // MYJVM8_NEW_H
