//
// Created by zj on 2025/7/22.
//

#ifndef THREAD_H
#define THREAD_H

#pragma once
#include "../util/BasicType.h"

#include "Stack.h"


class Frame;// 前向声明

class Thread {

private:
  //pc寄存器，即字节码行号
  int pc;
  //虚拟机栈
  Stack* stack;

public:
  Thread();
  int getPC();
  void setPC(int pc);
  void pushFrame(Frame &frame);
  Frame* popFrame();
  Frame* currentFrame();
  Frame* topFrame();
  Frame* getFrames();
  bool   isStackEmpty();
  void   clearStack();
  Frame  newFrame(u2 maxLocals, u2 maxStack);

};



#endif //THREAD_H
