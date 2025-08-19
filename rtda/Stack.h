//
// Created by zj on 2025/7/22.
//

#ifndef STACK_H
#define STACK_H

#pragma once
#include "../util/BasicType.h"
#include "Frame.h"

class Stack {

private:
  // 虚拟机栈栈的容量（最多可以容纳多少帧）
  u2 maxSize = 0;
  // 当前虚拟机栈的的当前大小，即帧的数量
  u2 size = 0;
  // 栈顶的帧
  Frame* topFrame;

public:
  Stack(u2 maxSize)  {
    this->maxSize = maxSize;
    this->size = 0;
    this->topFrame =nullptr;
    // this->topFrame = &topFrame;
  }
  Frame static initFrame(u2 maxLocals, u2 maxStack);
  void setStack(u2 maxSize);
  void push(Frame &frame);
  Frame* pop();
  Frame* top();
  Frame *getFrames();
  bool isEmpty();
  void   clear();

};



#endif //STACK_H
