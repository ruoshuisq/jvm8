//
// Created by zj on 2025/7/25.
//

#include "Instruction.h"
 Instruction::~Instruction() {  }
void Instruction::execute(Frame & frame, ByteCodeReader & byte_code_reader) {  }

void go_to(Frame & frame,int offset , ByteCodeReader & byte_code_reader) {
  int pc=frame.thread->getPC();
  int nextPC = pc + offset;
  frame.setNextPC(nextPC);
  byte_code_reader.reset(nullptr,nextPC);
}