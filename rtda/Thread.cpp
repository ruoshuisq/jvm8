//
// Created by zj on 2025/7/22.
//


#include "Thread.h"
#include "Frame.h"

Thread::Thread() {
  pc=0;
  stack=new Stack(1024);
}
int    Thread::getPC(){
  return pc;
}
void   Thread::setPC(int pc) {
  this->pc=pc;
}
void   Thread::pushFrame(Frame &frame){
  stack->push(frame);
}
Frame*  Thread::popFrame(){
  return stack->pop();
}
Frame*  Thread::currentFrame(){
  return stack->top();
}
Frame*  Thread::topFrame(){
  return stack->top();
}
Frame* Thread::getFrames() {
  return stack->getFrames();
}
bool   Thread::isStackEmpty() {
  return stack->isEmpty();
}
void   Thread::clearStack() {
  stack->clear();
}
Frame  Thread::newFrame(u2 maxLocals, u2 maxStack) {
  return Stack::initFrame(maxLocals,maxStack);
}