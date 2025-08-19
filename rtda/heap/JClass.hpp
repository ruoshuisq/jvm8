//
// Created by zj on 2025/7/29.
//

#ifndef MYJVM8_JCLASS_HPP
#define MYJVM8_JCLASS_HPP

#pragma once

#include <string.h>
#include <map>

#include "../../classpath/ClassFile.h"

#include "../Solt.hpp"

class Field;
class Method;
class ConstantPoolRun;
class ClassLoader;


class JClass {
private:

public:
  int accessFlags;
  ConstantPoolRun *constantPoolRun;
  std::map<int,Field>* fields;
  std::map<int,Method>* methods;
  int instanceSlotCount ;  //实例变量占据的空间大小
  int staticSlotCount   ;  //类变量占据的空间大小
  std::map<int,Solt>* staticVars;         //静态变量
  // com/xxx/xxx/Class
  std::string name;
  ClassLoader *loader; //类加载器指针
  // com/xxx/xxx/Class
  std::string superClassName;
  JClass * superClass;
  //com/xxx/xxx/Class
  std::map<int,std::string>* interfaceNames;
  std::map<int,JClass>*  interfaces;

  bool operator == (const JClass& other) const {
    return accessFlags == other.accessFlags
    and name == other.name
    and superClassName==other.superClassName
    and instanceSlotCount==other.instanceSlotCount
    and staticSlotCount==other.staticSlotCount;
  }

  bool operator != (const JClass& other) const {
    return !operator==(other);
  }

  JClass(ClassFile& classFile) ;

  bool isPublic()  ;

  bool isFinal()  ;

  bool isSuper() ;

  bool isInterface() ;

  bool isAbstract() ;

  bool isSynthetic() ;

  bool isAnnotation() ;

  bool isEnum() ;

  ConstantPoolRun* getConstantPoolRun() ;

  std::map<int,Solt>* getStaticVars()  ;

  // jvms 5.4.4
  bool isAccessibleTo(JClass other) ;

  std::string getPackageName()  ;

  Method* getMainMethod()  ;

  Method* getStaticMethod(std::string name,std::string descriptor ) ;

  Object  newObject(JClass &clazz) ;
  std::string getString(JClass &clazz)  ;
};

#endif // MYJVM8_JCLASS_HPP
