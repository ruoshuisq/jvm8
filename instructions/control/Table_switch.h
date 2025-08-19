//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_LOOKUP_SWITCH_H
#define MYJVM8_LOOKUP_SWITCH_H

#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

class Table_switch : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    byte_code_reader.skipPadding();
    int defaultOffset=byte_code_reader.readU4();
    int low=byte_code_reader.readU4();
    int high=byte_code_reader.readU4();
    int *jumpOffsets=new int[high-low+1];
    byte_code_reader.readU4s(high-low+1,jumpOffsets);
    int index =frame.operandStack_->popInt();
    int offset;
    if(index>=low && index<high){
      offset=jumpOffsets[index-low];
    }else{
      offset=defaultOffset;
    }
    go_to(frame, offset, byte_code_reader);
  }
};

#endif // MYJVM8_LOOKUP_SWITCH_H
