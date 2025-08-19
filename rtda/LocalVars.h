//
// Created by zj on 2025/7/22.
//

#ifndef LOCALVARS_H
#define LOCALVARS_H

#pragma once


#include "../util/BasicType.h"
#include "heap/Object.h"
#include "Solt.hpp"

// struct Solt {
//   // int type ;//值的类型：int、byte、float……
//   // char *val;//值
//   int byte4Int=0;
//   float byte4Float=0;
//   long byte8Long=0;
//   double byte8Double=0;
//   Object *ref=nullptr;
// };

class LocalVars {
private:
  Solt* localVars;
public:
  LocalVars(u2 maxLocals);
  void setInt(u2 index, int val);
  int getInt(u2 index);
  void setFloat(u2 index, float val);
  float getFloat(u2 index);
  void setDouble(u2 index, double val);
  double getDouble(u2 index);
  void setLong(u2 index, long val);
  long getLong(u2 index);
  void setRef(u2 index, Object &val);
  Object* getRef(u2 index);
  void setSolt(u2 index, Solt val);

};



#endif //LOCALVARS_H
