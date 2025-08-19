//
// Created by zj on 2025/7/25.
//

#ifndef INTERPRET_H
#define INTERPRET_H

#pragma once

#include "../classpath/AttributeInfo.h"
#include "../classpath/ClassReader.h"
#include "../instructions/ByteCodeReader.h"
#include "../instructions/InstructionFactory.h"
#include "../rtda/Thread.h"
#include "../instructions/Instruction.h"
#include "heap/Field.hpp"
#include "heap/Method.hpp"
#include "LocalVars.h"

class interpret {


};

// static void loop(Thread & thread,ByteCodeReader &byte_code_reader) {
//   do {
//     Frame * current_frame = thread.currentFrame();
//     //设置pc寄存器
//     int next_pc = current_frame->nextPC();
//     thread.setPC(next_pc);
//     byte_code_reader.reset(current_frame->method->getCodeAttributeInfo()->get().getCodeAttribute().code, next_pc); //TODO
//     //获取操作数
//     u1 opcode = byte_code_reader.readU1();
//     InstructionFactory *instruction_factory=new InstructionFactory();
//     Instruction *instruction = instruction_factory->createInstruction(opcode);
//     printf("pc:%2d inst:%s localVars:%2d, %2d \n",
//            next_pc,instruction->getName().data(),
//            current_frame->localVars_->getInt(1),
//            current_frame->localVars_->getInt(2));
//     instruction->execute(*current_frame,byte_code_reader);
//     current_frame->setNextPC(byte_code_reader.getPC());
//   }while (!thread.isStackEmpty());
// }
//
// static void run(MemberInfo & method,std::vector<std::string> args) {
//   Thread *thread=new Thread();
//   Frame new_frame = thread->newFrame(method.getCodeAttributeInfo()->get().getCodeAttribute().maxLocals,
//                                      method.getCodeAttributeInfo()->get().getCodeAttribute().maxStack);
//   new_frame.thread=thread;
//   thread->pushFrame(new_frame);
//   new_frame.method=&method;
//   Object *object=new Object();
//   new_frame.localVars_->setRef(0,*object);
//   ByteCodeReader *byte_code_reader=new ByteCodeReader(method.getCodeAttributeInfo()->get().getCodeAttribute().code);
//   loop(*thread,*byte_code_reader);
// }

static void loop(Thread & thread,ByteCodeReader &reader) {
  do {
    Frame * current_frame = thread.currentFrame();
    //设置pc寄存器
    int next_pc = current_frame->nextPC();
    thread.setPC(next_pc);
    reader.reset(current_frame->method->getCode(), next_pc); //TODO
    //获取操作数
    u1 opcode = reader.readU1();
    InstructionFactory *factory=new InstructionFactory();
    Instruction *instruction = factory->createInstruction(opcode);
    printf("pc:%2d inst:%s localVars:%2d, %2d \n",
           next_pc,instruction->getName().data(),
           current_frame->localVars_->getInt(1),
           current_frame->localVars_->getInt(2));
    instruction->execute(*current_frame,reader);
    current_frame->setNextPC(reader.getPC());
  }while (!thread.isStackEmpty());
}

static void run(Method & method,std::vector<std::string> args) {
  Thread *thread=new Thread();
  Frame new_frame = thread->newFrame(method.getMaxLocals(),
                                     method.getMaxStack());
  new_frame.thread=thread;
  thread->pushFrame(new_frame);
  new_frame.method=&method;
  ByteCodeReader *reader=new ByteCodeReader(method.getCode());
  loop(*thread,*reader);
}


#endif //INTERPRET_H
