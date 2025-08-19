//
// Created by zj on 2025/7/25.
//

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>

#include "../util/BasicType.h"
#include "../rtda/Frame.h"
#include "ByteCodeReader.h"
#include "../rtda/Thread.h"
void go_to(Frame & frame,int offset , ByteCodeReader & byte_code_reader);
class Instruction {
private:
  std::string name;
public:
  virtual ~Instruction() ;
  virtual void execute(Frame & frame, ByteCodeReader & byte_code_reader);
  void setName(std::string name){
    this->name=name;
  }
  std::string getName(){
    return name;
  }
};

#endif //INSTRUCTION_H
