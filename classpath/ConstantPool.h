//
// Created by zj on 2025/7/19.
//

#ifndef CONSTANTPOOL_H
#define CONSTANTPOOL_H
#include "ClassReader.h"

#include <map>

struct nameType {
  std::string name;
  std::string type;
};

class ConstantPool {
private:
  int size;
public:

  ConstantPool();

  //index,type
  std::map<int, int> tags;

  //index,value
  std::map<int, char *> data;

  std::string getClassNameByFieldInfo(u2 index);

  std::string getFieldName(u2 index);

  std::string getStringFromPool(u2 index);

  char *getAndNewFromPool(u2 index);

  std::string getClassPath(u2 index);

  std::string getMethodNameByMethodInfo(u2 index);

  std::string getDescriptorNameByMethodInfo(u2 index);

  std::string getClassNameByMethodInfo(u2 index);
};

#endif // CONSTANTPOOL_H
