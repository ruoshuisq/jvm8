//
// Created by zj on 2025/7/22.
//


#include "LocalVars.h"
#include "Solt.hpp"
#include "heap/Object.h"

 LocalVars::LocalVars(u2 maxLocals) {
  localVars=new Solt[maxLocals];
 }

void   LocalVars::setInt(u2 index, int val) {
  localVars[index].byte4Int=val;
 }
int    LocalVars::getInt(u2 index){
  return localVars[index].byte4Int;
 }
void   LocalVars::setFloat(u2 index, float val){
  localVars[index].byte4Float=val;
 }
float  LocalVars:: getFloat(u2 index){
  return localVars[index].byte4Float;
 }
void   LocalVars::setDouble(u2 index, double val){
  localVars[index].byte8Double=val;
 }
double LocalVars::getDouble(u2 index){
  return localVars[index].byte8Double;
 }
void   LocalVars::setLong(u2 index, long val){
 localVars[index].byte8Long=val;
}
long   LocalVars::getLong(u2 index){
  return localVars[index].byte8Long;
 }
void   LocalVars::setRef(u2 index, Object &val){
 localVars[index].ref=&val;
}
Object* LocalVars::getRef(u2 index){
  return  localVars[index].ref;
}
void   LocalVars::setSolt(u2 index, Solt val){
 localVars[index]=val;
}