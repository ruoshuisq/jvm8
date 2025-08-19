//
// Created by zj on 2025/7/22.
//

#ifndef FRAME_H
#define FRAME_H


#pragma once
#include "LocalVars.h"
#include "OperandStack.h"
#include "heap/Method.hpp"

class Thread;// 前向声明

class Frame {
  // Thread thread_;
  int nextPC_; // the next instruction after the call
public:
  int hash;
  Method* method;
  Thread* thread;
  LocalVars *localVars_;
  OperandStack *operandStack_;
  Frame(LocalVars &localVars,OperandStack &operandStack);
  Frame *lower; // 单链表结构，头插法
  void setLower(Frame &frame);
  // LocalVars localVars() ;
  // OperandStack operandStack() ;
  // Thread thread();
  int nextPC()  ;
  void setNextPC(int nextPC ) ;

  void revertNextPC() ;

};

#endif // FRAME_H
