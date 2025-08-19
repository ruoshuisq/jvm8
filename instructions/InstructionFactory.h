//
// Created by zj on 2025/7/25.
//

#ifndef INSTRUCTIONFACTORY_H
#define INSTRUCTIONFACTORY_H
#include "ByteCode.h"
#include "Instruction.h"
#include "constants/Constants.h"

class InstructionFactory {
public:
  Instruction* createInstruction(u1 opcode);
};


#endif //INSTRUCTIONFACTORY_H
