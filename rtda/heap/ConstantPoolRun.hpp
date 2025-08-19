//
// Created by zj on 2025/7/29.
//

#ifndef MYJVM8_CONSTANTPOOLRUN_HPP
#define MYJVM8_CONSTANTPOOLRUN_HPP

#pragma once

#include <map>
#include <string>


class ConstantPool;
class Constant;
class JClass;
class ConstantPoolRun {
private:
  std::map<int,Constant*>*  constants;
public:
  ConstantPoolRun(ConstantPool & constantPool,JClass & jClass);
  JClass * jClass;
  Constant* getConstant(int index);
  std::string getString(int index);
};



#endif // MYJVM8_CONSTANTPOOLRUN_HPP
