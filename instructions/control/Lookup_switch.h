//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_LOOKUP_SWITCH_H
#define MYJVM8_LOOKUP_SWITCH_H

#include "../../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

class Lookup_switch : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    byte_code_reader.skipPadding();
    int defaultOffset=byte_code_reader.readU4();
    int npairs=byte_code_reader.readU4();
    // [key value key value...]
    int *matchOffsets=new int[npairs * 2];
    byte_code_reader.readU4s(npairs * 2,matchOffsets);
    int key =frame.operandStack_->popInt();
    for(int i=0;i<npairs * 2;i+=2){
      if(matchOffsets[i] == key){
        int offset=matchOffsets[i+1];
        go_to(frame, offset, byte_code_reader);
        return;
      }
    }
    go_to(frame, defaultOffset, byte_code_reader);
  }
};

#endif // MYJVM8_LOOKUP_SWITCH_H
