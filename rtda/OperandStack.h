//
// Created by zj on 2025/7/22.
//

#ifndef OPERANDSTACK_H
#define OPERANDSTACK_H

#pragma once

#include "../util/BasicType.h"

#include <stdlib.h>
#include <cstdio>

#include "Solt.hpp"
#include "heap/Object.h"

class OperandStack {
private:
  u2 size;
  Solt *slots;
  // std::stack<Solt> slots; // 创建栈
public:
  OperandStack(u2 maxStack);
  void pushInt(int val);
  int popInt();
  void pushFloat(float val);
  float popFloat();
  void pushLong(long val);
  long popLong();
  void pushDouble(double val);
  double popDouble();
  void pushObject(Object &val);
  Object* popObject();
  void pushSolt(Solt &val);
  Solt popSolt();

};



#endif //OPERANDSTACK_H
