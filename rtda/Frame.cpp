//
// Created by zj on 2025/7/22.
//


#include "Frame.h"

#include "Thread.h"

Frame::Frame(LocalVars &localVars, OperandStack &operandStack)
     {
  localVars_=&localVars;
  operandStack_=&operandStack;
  hash=rand();
  nextPC_=0;
}


void Frame::setLower(Frame &frame) {
   lower=&frame;
 }

// LocalVars Frame::localVars() {
//    return *localVars_;
//  }
// OperandStack Frame::operandStack() {
//    return &operandStack_;
//  }
// Thread Frame::thread(){
// }
int Frame::nextPC()  {
   return nextPC_;
 }
void Frame::setNextPC(int nextPC ) {
   nextPC_=nextPC;
 }

void Frame::revertNextPC() {
 }
