//
// Created by zj on 2025/7/22.
//


#include "Stack.h"

#include "LocalVars.h"
#include "OperandStack.h"

Frame  Stack::initFrame(u2 maxLocals, u2 maxStack) {
  LocalVars *localVars = new LocalVars(maxLocals);
  OperandStack *operandStack = new OperandStack(maxStack);
  Frame *frame = new Frame(*localVars, *operandStack);
  frame->lower=nullptr;
  return *frame;
}

void Stack::setStack(u2 maxSize) {
  this->maxSize=maxSize;
   size=0;
 }

void   Stack::push(Frame &frame){
  if(size>=maxSize) {
    printf("java.lang.StackOverflowError");
    return;
  }
  if (&topFrame != nullptr) {
    frame.lower=topFrame;
  }
  topFrame=&frame;
  size++;
}
Frame*  Stack::pop(){
  if (&topFrame==nullptr) {
    printf("jvm stack is empty!");
  }
  Frame *top =topFrame;
  topFrame = top->lower;
  size--;
  return top;
}
Frame*  Stack::top(){
  if (&topFrame==nullptr) {
    printf("jvm stack is empty!");
  }
  return topFrame;
}
Frame* Stack::getFrames(){
  std::allocator<Frame> alloc;
  Frame *frames = alloc.allocate(size);
  // Frame *frames=new Frame[size];//TODO
  Frame *tmp=topFrame;
  for (int i=0;i<size;i++) {
    frames[i]=*tmp;
    tmp=topFrame->lower;
  }
  for (int i=0;i<size;i++) {
    printf("in--%d\n",frames[i].hash);
  }
  return frames;
}
bool   Stack::isEmpty(){
  return topFrame==nullptr;
}
void   Stack::clear(){
  do
  {
    pop();
  }
    while (!isEmpty()) ;
}