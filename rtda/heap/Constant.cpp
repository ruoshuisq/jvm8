//
// Created by stephensdesktop on 2025/7/30.
//


#include "Constant.hpp"

#include "ClassLoader.hpp"
#include "ConstantPoolRun.hpp"
#include "../../instructions/ByteCodeReader.h"

#include "JClass.hpp"
#include "Field.hpp"
void ConstantInteger::castData(char *data)  {
    val = atoi(data);
}

int ConstantInteger::getValue() {
    return val;
}

void ConstantFloat::castData(char *data)  {
    val = atof(data);
}

float ConstantFloat::getValue() {
    return val;
}

void ConstantLong::castData(char *data)  {
    val = atol(data);
}

long ConstantLong::getValue() {
    return val;
}

void ConstantDouble::castData(char *data)  {
    val = strtod(data, nullptr);
}

double ConstantDouble::getValue() {
    return val;
}

void ConstantString::castData(char *data)  {
    str = data;
}

std::string *ConstantString::getValue() {
    return &str;
}

void ConstantString::setConstantPoolRun(ConstantPoolRun &constantPoolRun) {
    this->constantPoolRun = &constantPoolRun;
}

void ConstantUtf8::castData(char *data)  {
    str = data;
}

std::string *ConstantUtf8::getValue() {
    return &str;
}

void ConstantClass::castData(char *data)  {
    // nameIndex=atoi(data);
    className = data;
}

std::string *ConstantClass::getValue() {
    return &className;
}

void ConstantClass::setConstantPoolRun(ConstantPoolRun &constantPoolRun) {
    this->constantPoolRun = &constantPoolRun;
}

void ConstantClass::setJClass(JClass &jClass) {
    this->jClass = &jClass;
}

void ConstantClass::resolvedClass() {
    if (this->jClass == nullptr) {
        resolveClassRef();
    }
}

// jvm规范 5.4.3.1 类符号引用解析步骤
// 如果类D通过符号引用N引用类C的话，要解析N，先用D的类加载器加载C，然后检查D是否有权限访问C，如果没有，则抛出IllegalAccessError异常。
// 也就是说，如果类D想访问类C，需要满足两个条件之一：C是public，或者C和D在同一个运行时包内
void ConstantClass::resolveClassRef() {
    ConstantPoolRun *constant_pool_run = this->constantPoolRun;
    JClass *d = constant_pool_run->jClass;
    JClass *c = d->loader->loadClass(this->className);
    if (!c->isAccessibleTo(*d)) {
        printf("java.lang.IllegalAccessError");
    } else {
        this->jClass = c;
    }
}

// jvm 5.4.4
Field* lookupField(JClass & c,std::string name,std::string descriptor ) {
    for (std::pair<const int, Field> field : *c.fields) {
        if (strcmp(field.second.name.data(), name.data())==0 &&
            strcmp(field.second.descriptor.data(), descriptor.data())==0 ) {
            return &field.second;
            }
    }
    for (std::pair<const int, JClass> pair : *c.interfaces) {
        Field * lookup_field = lookupField(pair.second,name,descriptor);
        if(lookup_field!=nullptr) {
            return lookup_field;
        }
    }
    if (c.superClass!=nullptr) {
        return lookupField(*c.superClass, name, descriptor);
    }
    return nullptr;
}

//jvm规范 5.4.3.1 字段符号引用的解析步骤
void ConstantField::resolvedField() {
    if (this->field == nullptr) {
        resolveFieldRef();
    }
}
void ConstantField::resolveFieldRef(){
    JClass * d = this->constantPoolRun->jClass;
    this->resolvedClass();
    JClass * c = this->jClass;
    Field * lookup_field = lookupField(*c,this->name,this->descriptor);
    if (lookup_field == nullptr) {
        printf("java.lang.NoSuchFieldError");//TODO未实现退出
    }
    if (!lookup_field->isAccessibleTo(*d)) {
        printf("java.lang.IllegalAccessError");//TODO未实现退出
    }
    this->field = lookup_field;
}



