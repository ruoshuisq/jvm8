//
// Created by stephensdesktop on 2025/7/29.
//

#ifndef METHOD_HPP
#define METHOD_HPP

#pragma once
#include <string>

#include "../classpath/MemberInfo.h"
#include "../classpath/AttributeInfo.h"
class JClass;
class Method {
private:
    int accessFlags;
    std::string name;
    std::string descriptor;
    int maxStack; //操作数栈大小
    int maxLocals; //局部变量表大小
    char *code; //字节码
    JClass *jClass; //存放Class结构体指针，这样可以通过字段或方法访问到它所属的类
public:
    Method(MemberInfo & memberInfo, JClass & jClass);

    bool isPublic();

    bool isPrivate();

    bool isProtected();

    bool isStatic();

    bool isFinal();

    bool isSynthetic();

    std::string getName();

    std::string getDescriptor();

    JClass getClass();

    // jvms 5.4.4
    bool isAccessibleTo(JClass &other);

    bool isSynchronized();

    bool isBridge();

    bool isVarargs();

    bool isNative();

    bool isAbstract();

    bool isStrict();

    int getMaxStack();

    int getMaxLocals();

    char* getCode();
};


#endif //METHOD_HPP
