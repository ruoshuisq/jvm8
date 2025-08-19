//
// Created by zj on 2025/7/22.
//


#include "OperandStack.h"
#include "LocalVars.h"

OperandStack::OperandStack(u2 maxStack) {
  slots=new Solt[maxStack];
  size=0;
}

void   OperandStack::pushInt(int val){
  slots[size].byte4Int=val;
  size=size+1;
}
int    OperandStack::popInt(){
  size--;
  return slots[size].byte4Int;
}
void   OperandStack::pushFloat(float val){
  slots[size].byte4Float=val;
  size=size+1;
}
float  OperandStack:: popFloat(){
  size--;
  return  slots[size].byte4Float;
}
void   OperandStack:: pushLong(long val){
  slots[size].byte8Long=val;
  size=size+1;
}
long   OperandStack:: popLong(){
  size--;
  return slots[size].byte8Long;
}
void   OperandStack::  pushDouble(double val){
  slots[size].byte8Double=val;
  size++;
}
double OperandStack::popDouble(){
  size--;
  return  slots[size].byte8Double;
}
void   OperandStack::pushObject(Object &val){
//  printf("push before--%p\n",slots[size].ref);
  slots[size].ref=&val;
//  printf( "push after --%p\n",slots[size].ref);
  size++;
}
Object* OperandStack::popObject(){
  size--;
//  printf("pop before --%p\n",slots[size].ref);
  return  slots[size].ref;
}
 void   OperandStack::pushSolt(Solt &val) {
    slots[size]=val;
    size++;
 }
Solt   OperandStack::popSolt() {
  size--;
  return slots[size];
}