//
// Created by zj on 2025/7/29.
//


#include "JClass.hpp"

#include "ConstantPoolRun.hpp"
#include "Field.hpp"
#include "Method.hpp"
#include "ClassLoader.hpp"
#include "Constant.hpp"
#include "../LocalVars.h"

JClass::JClass(ClassFile& classFile) {
    accessFlags=classFile.accessFlags;
    constantPoolRun=new ConstantPoolRun(*classFile.constantPool,*this);

    name = constantPoolRun->getString(classFile.thisClass);
    superClassName = constantPoolRun->getString(classFile.superClass);
    //在堆中分配
    std::map<int,std::string> *interfaceNames=new std::map<int,std::string> ();
    classFile.InterfaceNames(*interfaceNames);//todo 可能有问题，未测试
    this->interfaceNames=interfaceNames;

    //字段
    std::map<int,Field> *fieldsRs=new std::map<int,Field> ();
    for (auto iter = classFile.fields->begin(); iter != classFile.fields->end(); ++iter) {
        MemberInfo member_info = iter->second;
        int index =iter->first;
        auto *field=new Field(member_info,*this);
        fieldsRs->insert(std::pair<int,Field>(index, *field));
    }
    // for (std::pair< int, MemberInfo> fieldTmp : classFile.fields) {
    //     Field *field=new Field(fieldTmp.second,*this);
    //     fieldsRsP[fieldTmp.first]=*field;
    // }
    this->fields=fieldsRs;
    //方法
    std::map<int,Method> *methodsRs=new std::map<int,Method> ();

    for (auto iter = classFile.methods->begin(); iter != classFile.methods->end(); ++iter) {
        MemberInfo member_info = iter->second;
        int index =iter->first;
        auto *method=new Method(member_info,*this);
        methodsRs->insert(std::pair<int,Method>(index, *method));
    }
    // for (std::pair< int, MemberInfo> methodTmp : classFile.methods) {
    //     Method *method=new Method(methodTmp.second,*this);
    //     methodsRsP[methodTmp.first]=*method;
    // }
    this->methods=methodsRs;
}

bool JClass::isPublic()  {
    return this->accessFlags&ACC_PUBLIC != 0;
}

bool JClass::isFinal()  {
    return this->accessFlags&ACC_FINAL != 0;
}

bool JClass::isSuper() {
    return this->accessFlags&ACC_SUPER != 0;
}

bool JClass::isInterface() {
    return this->accessFlags&ACC_INTERFACE != 0;
}

bool JClass::isAbstract() {
    return this->accessFlags&ACC_ABSTRACT != 0;
}

bool JClass::isSynthetic() {
    return this->accessFlags&ACC_SYNTHETIC != 0;
}

bool JClass::isAnnotation() {
    return this->accessFlags&ACC_ANNOTATION != 0;
}

bool JClass::isEnum() {
    return this->accessFlags&ACC_ENUM != 0;
}

ConstantPoolRun* JClass::getConstantPoolRun() {
    return this->constantPoolRun;
}

std::map<int,Solt>* JClass::getStaticVars()  {
    return this->staticVars;
}

// jvms 5.4.4
bool JClass::isAccessibleTo(JClass other) {
    return this->isPublic() ||
        this->getPackageName() == other.getPackageName();
}

std::string JClass::getPackageName()  {
    std::size_t find_last_of = this->name.find_last_of("/");
    std::string packageName = this->name.substr(0,find_last_of);
    return packageName;
}

Method* JClass::getMainMethod()  {
    return this->getStaticMethod("main", "([Ljava/lang/String;)V");
}

Method* JClass::getStaticMethod(std::string name,std::string descriptor) {
    for (std::pair<int,Method> methodPair: *this->methods) {
        if(methodPair.second.isStatic() &&
            strcmp(methodPair.second.getName().data(),name.data())==0 &&
            strcmp(methodPair.second.getDescriptor().data(),descriptor.data())==0) {
            return &methodPair.second;
        }
    }
}

Object  JClass::newObject(JClass &clazz) {
    Object *object=new Object();
    object->jClass=this;
    object->fields=new std::map<int,Solt>();
    //初始化实例变量
    int i=0;
    for (std::pair<const int, Field> field : *this->fields) {
        if(!field.second.isStatic()) {
            i++;
            switch (hash_compile_time(field.second.getDescriptor().data())) {
                case "Z"_hash "B"_hash "C"_hash "S"_hash "I"_hash: {
                    Solt *solt=new Solt();
                    solt->byte4Int=0;
                    auto pairs = *object->fields;
                    pairs[i]=*solt;
                }
                case "J"_hash: {
                    Solt *solt=new Solt();
                    solt->byte8Long=0;
                    auto pairs = *object->fields;
                    pairs[i]=*solt;
                    i++;
                }
                case "F"_hash: {
                    Solt *solt=new Solt();
                    solt->byte4Float=0.0;
                    auto pairs = *object->fields;
                    pairs[i]=*solt;
                }
                case "D"_hash: {
                    Solt *solt=new Solt();
                    solt->byte8Double=0;
                    auto pairs = *object->fields;
                    pairs[i]=*solt;
                    i++;
                }
                case "Ljava/lang/String;"_hash:
                    ; //TODO
                default: {
                    //TODO
                }
            }
        }
    }
    object->instanceSlotCount=this->instanceSlotCount;
}
std::string JClass::getString(JClass &clazz)   {
    return clazz.name;
}
