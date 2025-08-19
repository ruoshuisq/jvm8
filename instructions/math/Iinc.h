//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_IINC_H
#define MYJVM8_IINC_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
class Iinc : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    int index=byte_code_reader.readU1();
    int constNum=byte_code_reader.readU1();
    int val =frame.localVars_->getInt(index);
    val+=constNum;
    frame.localVars_->setInt(index,val);
  }
};

#endif // MYJVM8_IINC_H
