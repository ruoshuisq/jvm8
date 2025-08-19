//
// Created by zj on 2025/7/29.
//


#include "ConstantPoolRun.hpp"

#include <winsock2.h>

#include "Constant.hpp"
#include "JClass.hpp"
#include "../classpath/ConstantPool.h"

Constant* createConstant(int index,ConstantPool & constantPool,ConstantPoolRun & constantPoolRun) {
  int tag=constantPool.tags[index];
  switch(tag){
  case CONSTANT_Utf8: {
    Constant *constant=new ConstantUtf8();
    ConstantUtf8 *constantUtf8=static_cast<ConstantUtf8*>(constant);
    constantUtf8->castData(constantPool.data[index]);
    printf("第%d个，类型utf-8，值 %s\n", index, constantUtf8->getValue()->data());
    return constantUtf8;
  }
  case CONSTANT_Integer: {
    Constant *constant=new ConstantInteger();
    ConstantInteger *constantInteger=static_cast<ConstantInteger*>(constant);
    constantInteger->castData(constantPool.data[index]);
    printf("第%d个，类型Integer，值 %d\n", index, constantInteger->getValue());
    return constantInteger;
  }
  case CONSTANT_Float: {
    Constant *constant=new ConstantFloat();
    ConstantFloat *constantFloat=static_cast<ConstantFloat*>(constant);
    constantFloat->castData(constantPool.data[index]);
    printf("第%d个，类型Float，值 %f\n", index, constantFloat->getValue());
    return constantFloat;
  }
  case CONSTANT_Long: {
    Constant *constant=new ConstantLong();
    ConstantLong *constantLong=static_cast<ConstantLong*>(constant);
    constant->castData(constantPool.data[index]);
    printf("第%d个，类型Long，值 %ld\n", index, constantLong->getValue());
    return constantLong;
  }
  case CONSTANT_Double: {
    Constant *constant=new ConstantDouble();
    ConstantDouble *constantDouble=static_cast<ConstantDouble*>(constant);
    constant->castData(constantPool.data[index]);
    printf("第%d个，类型Double，值 %fd\n", index, constantDouble->getValue());
    return constantDouble;
  }
  case CONSTANT_Class: {
    Constant *constant=new ConstantClass();
    int nameIndex=atoi(constantPool.data[index]);
    ConstantClass *constantClass=static_cast<ConstantClass*>(constant);
    constantClass->castData(constantPool.data[nameIndex]);
    constantClass->setConstantPoolRun(constantPoolRun);
    constantClass->setJClass(*constantPoolRun.jClass);
    printf("第%d个，类型Class，类名称 %s\n", index, constantClass->getValue()->data());
    return constantClass;
  }
  case CONSTANT_String: {
    Constant *constant=new ConstantString();
    int stringIndex=atoi(constantPool.data[index]);
    ConstantString *constantString=static_cast<ConstantString*>(constant);
    constantString->castData(constantPool.data[stringIndex]);
    constantString->setConstantPoolRun(constantPoolRun);
    printf("第%d个，类型string，值 %s\n", index, constantString->getValue()->data());
    return constantString;
  }
  case CONSTANT_Fieldref: {
    Constant *constant=new ConstantField();
    ConstantField *constantField=static_cast<ConstantField*>(constant);
    constantField->setConstantPoolRun(constantPoolRun);
    constantField->setJClass(*constantPoolRun.jClass);

    //左16位存储classIndex 右16为存储nameAndTypeIndex
    long tmp=ntohl(atol(constantPool.data[index]));
    long classIndex=tmp>>16;
    long classNameIndex=atol(constantPool.data[classIndex]);
    std::string className=constantPool.data[classNameIndex];
    constantField->setClassName(className);
    long nameAndTypeIndex=tmp<<16>>16;

    long nameAndTypeTmp=ntohl(atol(constantPool.data[nameAndTypeIndex]));
    long nameIndex=nameAndTypeTmp>>16;
    long typeIndex=nameAndTypeTmp<<16>>16;
    std::string name=constantPool.data[nameIndex];
    std::string descriptor=constantPool.data[typeIndex];
    constantField->setName(name);
    constantField->setDescriptor(descriptor);
    printf("第%d个，类型filed,字段类型名 %s，字段名称 %s，字段描述符 %s \n", index,
           className.data(),name.data(),descriptor.data());
    return constantField;
  }
  case CONSTANT_Methodref: {
    Constant *constant=new ConstantMethod();
    ConstantMethod *constantMethod=static_cast<ConstantMethod*>(constant);
    constantMethod->setConstantPoolRun(constantPoolRun);
    constantMethod->setJClass(*constantPoolRun.jClass);

    //左16位存储classIndex 右16为存储nameAndTypeIndex
    //大端转小端，即网络转主机
    long tmp=ntohl(atol(constantPool.data[index]));
    long classIndex=tmp>>16;
    long classNameIndex=atol(constantPool.data[classIndex]);
    std::string className=constantPool.data[classNameIndex];
    constantMethod->setClassName(className);
    long nameAndTypeIndex=tmp<<16>>16;

    long nameAndTypeTmp=ntohl(atol(constantPool.data[nameAndTypeIndex]));
    long nameIndex=nameAndTypeTmp>>16;
    long typeIndex=nameAndTypeTmp<<16>>16;
    std::string name=constantPool.data[nameIndex];
    std::string descriptor=constantPool.data[typeIndex];
    constantMethod->setName(name);
    constantMethod->setDescriptor(descriptor);
    printf("第%d个，类型method,方法的类名 %s，方法名称 %s，方法描述符 %s \n", index,
           className.data(),name.data(),descriptor.data());
    return constantMethod;
  }
  case CONSTANT_InterfaceMethodref: {
    Constant *constant=new ConstantInterface();
    ConstantInterface *constantInterface=static_cast<ConstantInterface*>(constant);
    constantInterface->setConstantPoolRun(constantPoolRun);
    constantInterface->setJClass(*constantPoolRun.jClass);

    //左16位存储classIndex 右16为存储nameAndTypeIndex
    long tmp=ntohl(atol(constantPool.data[index]));
    long classIndex=tmp>>16;
    long classNameIndex=atol(constantPool.data[classIndex]);
    std::string className=constantPool.data[classNameIndex];
    constantInterface->setClassName(className);
    long nameAndTypeIndex=tmp<<16>>16;

    long nameAndTypeTmp=ntohl(atol(constantPool.data[nameAndTypeIndex]));
    long nameIndex=nameAndTypeTmp>>16;
    long typeIndex=nameAndTypeTmp<<16>>16;
    std::string name=constantPool.data[nameIndex];
    std::string descriptor=constantPool.data[typeIndex];
    constantInterface->setName(name);
    constantInterface->setDescriptor(descriptor);
    printf("第%d个，类型interface,接口类型名 %s，接口名称 %s，接口描述符 %s \n", index,
           className.data(),name.data(),descriptor.data());
    return constantInterface;
  }
  case CONSTANT_NameAndType: {
    // Constant *constant=new ConstantNameAndType();
    // ConstantNameAndType *constantField=static_cast<ConstantNameAndType*>(constant);
    // constant->castData(constantPool.data[tag]);
    // char* name;
    // char* type;
    // constantField->getNameAndDescriptor(name,type);
    // printf("第%d个，类型NameAndType，名称%s，描述%s\n", index
    //        ,name,type);
    // return constant;
    return nullptr;
  }
  case CONSTANT_MethodHandle: {
    //    int *temp = new int;
    //    short referenceKind = reader.readU1();       // 读取1个字节
    //    short referenceIndex = reader.readU2(); // 读取两个字节
    //    *temp = htonl(
    //        referenceKind << 16 |
    //        referenceIndex); // 左8位存储referenceKind 右16为存储referenceIndex
    //    (constant_pool.data[i]) = (char *)temp; // 存储在常量池
    //    printf("第%d个，类型MethodHandle，值%X\n", i,
    //           htonl(*(int *)constant_pool.data[i]));
    return nullptr;
  }
  case CONSTANT_MethodType: {
    //    char *temp = new char;
    //    *temp = reader.readU2();      // 读取两个字节
    //    constant_pool.data[i] = temp; // 存储在常量池
    //    printf("第%d个，类型MethodType，值%d\n", i, *constant_pool.data[i]);
    return nullptr;
  }
  case CONSTANT_InvokeDynamic: {
    //    int *temp = new int;
    //    short bootstrapMethodAttrIndex = reader.readU2();       // 读取两个字节
    //    short nameAndTypeIndex = reader.readU2(); // 读取两个字节
    //    *temp = htonl(
    //        bootstrapMethodAttrIndex << 16 |
    //        nameAndTypeIndex); // 左16位存储classIndex 右16为存储nameAndTypeIndex
    //    (constant_pool.data[i]) = (char *)temp; // 存储在常量池
    //    printf("第%d个，类型InvokeDynamic，值%X\n", i,
    //           htonl(*(int *)constant_pool.data[i]));
    return nullptr;
  }

  default:
    return nullptr;
  }
}

ConstantPoolRun::ConstantPoolRun(ConstantPool & constantPool,JClass &jClass){
  this->jClass=&jClass;
  int len=constantPool.data.size();
  this->constants=new std::map<int,Constant*>();
  for(int i=1;i<len;i++){
    Constant *constant=createConstant(i,constantPool,*this);
    if(constant!=nullptr) {
      this->constants->insert(std::pair<int, Constant*>(i, constant));
    }
    int tag=constantPool.tags[i];
    if(tag==CONSTANT_Long || tag==CONSTANT_Double){
      i++;
    }
  }
}

Constant* ConstantPoolRun::getConstant(int index) {
  std::map<int, Constant*>::iterator iter = constants->find(index);
  if (iter != constants->end()) {
    return iter->second;
  }
  return nullptr;
}

std::string ConstantPoolRun::getString(int index) {
  Constant * constant = getConstant(index);
  switch(constant->type){
  case CONSTANT_Utf8: {
    ConstantUtf8 *constantUtf8=static_cast<ConstantUtf8*>(constant);
    return constantUtf8->getString();
  }
  case CONSTANT_Integer: {
    ConstantInteger *constantInteger=static_cast<ConstantInteger*>(constant);
    return constantInteger->getString();
  }
  case CONSTANT_Float: {
    ConstantFloat *constantFloat=static_cast<ConstantFloat*>(constant);
    return constantFloat->getString();
  }
  case CONSTANT_Long: {
    ConstantLong *constantLong=static_cast<ConstantLong*>(constant);
    return constantLong->getString();
  }
  case CONSTANT_Double: {
    ConstantDouble *constantDouble=static_cast<ConstantDouble*>(constant);
    return constantDouble->getString();
  }
  case CONSTANT_Class: {
    ConstantClass *constantClass=static_cast<ConstantClass*>(constant);
    return constantClass->getString();
  }
  case CONSTANT_String: {
    ConstantString *constantString=static_cast<ConstantString*>(constant);
    return constantString->getString();
  }
  case CONSTANT_Fieldref: {
    ConstantField *constantField=static_cast<ConstantField*>(constant);
    return constantField->getString();
  }
  case CONSTANT_Methodref: {
    ConstantMethod *constantMethod=static_cast<ConstantMethod*>(constant);
    return constantMethod->getString();
  }
  case CONSTANT_InterfaceMethodref: {
    ConstantInterface *constantInterface=static_cast<ConstantInterface*>(constant);
    return constantInterface->getString();
  }
  case CONSTANT_NameAndType: {
    return nullptr;
  }
  case CONSTANT_MethodHandle: {
    return nullptr;
  }
  case CONSTANT_MethodType: {
    return nullptr;
  }
  case CONSTANT_InvokeDynamic: {
    return nullptr;
  }
  default:
    return nullptr;
  }
  return constant->getString();
}