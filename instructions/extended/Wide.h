//
// Created by zj on 2025/7/27.
//

#ifndef MYJVM8_WIDE_H
#define MYJVM8_WIDE_H

#include "../rtda/Frame.h"
#include "../ByteCodeReader.h"
#include "../Instruction.h"
#include "../rtda/Thread.h"
#include "../rtda/OperandStack.h"
#include "../rtda/LocalVars.h"
#include "../rtda/Solt.hpp"

class Wide : public Instruction{
  void execute(Frame & frame, ByteCodeReader & byte_code_reader) override {
    u1 opcode=byte_code_reader.readU1();
    switch (opcode) {
      case 0x15:
    {
        int index=byte_code_reader.readU2();
        int value =frame.localVars_->getInt(index);
        frame.operandStack_->pushInt(value);
        break;
      }

          case 0x16:{
            int index=byte_code_reader.readU2();
            long value =frame.localVars_->getLong(index);
            frame.operandStack_->pushLong(value);
            break;
          }
          case 0x17:{
            int index=byte_code_reader.readU2();
            float value =frame.localVars_->getFloat(index);
            frame.operandStack_->pushFloat(value);
            break;
          }
          case 0x18:{
            int index=byte_code_reader.readU2();
            double value =frame.localVars_->getDouble(index);
            frame.operandStack_->pushDouble(value);
            break;
          }
          case 0x19:{
            int index=byte_code_reader.readU2();
            Object *value =frame.localVars_->getRef(index);
            frame.operandStack_->pushObject(*value);
            break;
          }
          case 0x36:{
            int index=byte_code_reader.readU2();
            int value =frame.operandStack_->popInt();
            frame.localVars_->setInt(index,value);
            break;
          }
          case 0x37:{
            int index=byte_code_reader.readU2();
            long value =frame.operandStack_->popLong();
            frame.localVars_->setLong(index,value);
            break;
          }
          case 0x38:{
            int index=byte_code_reader.readU2();
            float value =frame.operandStack_->popFloat();
            frame.localVars_->setFloat(index,value);
            break;
          }
          case 0x39:{
            int index=byte_code_reader.readU2();
            double value =frame.operandStack_->popDouble();
            frame.localVars_->setDouble(index,value);
            break;
          }
          case 0x3a:{
            int index=byte_code_reader.readU2();
            Object *value =frame.operandStack_->popObject();
            frame.localVars_->setRef(index,*value);
            break;
          }
          case 0x84:{
            int index=byte_code_reader.readU2();
            int constNum=byte_code_reader.readU2();
            int val =frame.localVars_->getInt(index);
            val+=constNum;
            frame.localVars_->setInt(index,val);
            break;
          }
          case 0xa9: // ret
        printf("Unsupported opcode: 0xa9!");
      }
  }
};
#endif // MYJVM8_WIDE_H
