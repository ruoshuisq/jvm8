//
// Created by zj on 2025/7/18.
//

#ifndef CLASSFILE_H
#define CLASSFILE_H
#include <string>

#include "ClassReader.h"
#include "MemberInfo.h"

#include <vector>
/*
ClassFile {
    u4             magic;
    u2             minor_version;
    u2             major_version;
    u2             constant_pool_count;
    cp_info        constant_pool[constant_pool_count-1];
    u2             access_flags;
    u2             this_class;
    u2             super_class;
    u2             interfaces_count;
    u2             interfaces[interfaces_count];
    u2             fields_count;
    field_info     fields[fields_count];
    u2             methods_count;
    method_info    methods[methods_count];
    u2             attributes_count;
    attribute_info attributes[attributes_count];
}
*/
//struct ClassFileST {
//  u4 magic;
//  u2 minorVersion;
//  u2 majorVersion;
//  ConstantPool *constantPool;
//  u2 accessFlags;
//  //类索引
//  u2 thisClass;
//  //超类索引
//  u2 superClass;
//  //接口索引表
//  u2 *interfaces;
//  std::map<int,MemberInfo> *fields={};
//  int fieldCount;
//  std::map<int,MemberInfo> *methods={};
//  int methodsCount;
//  std::map<int,AttributeInfo> *attributes={};
//  int attributesCount;
//};

class ClassFile {
private:


public:
  u4 magic;
  u2 minorVersion;
  u2 majorVersion;
  ConstantPool *constantPool=new ConstantPool();
  u2 accessFlags;
  //类索引
  u2 thisClass;
  //超类索引
  u2 superClass;
  //接口索引表
  u2 *interfaces;
  std::map<int,MemberInfo> *fields={};
  int fieldCount{};
  std::map<int,MemberInfo> *methods={};
  int methodsCount{};
  std::map<int,AttributeInfo> *attributes={};
  int attributesCount;
//  ClassFileST *class_file_st_;
  void parse(ClassReader &cr);
  u1 MinorVersion() ;
  u1 MajorVersion() ;
  ConstantPool getConstantPool() ;
  u1 AccessFlags() ;
  std::map<int,MemberInfo> Fields() ;
  std::map<int,MemberInfo> Methods() ;
  std::string ClassName() ;
  std::string SuperClassName() ;
  void InterfaceNames(std::map<int,std::string> & interfaceNames) ;


};

#endif // CLASSFILE_H
