//
// Created by stephensdesktop on 2025/7/29.
//

#ifndef FIELD_H
#define FIELD_H

#pragma once
#include <string>
#include "../classpath/MemberInfo.h"


class JClass;
class ClassLoader;

class Field {
private:

public:
    int accessFlags;
    std::string name;
    std::string descriptor;
    JClass * jClass; //存放Class结构体指针，这样可以通过字段或方法访问到它所属的类
    int constValueIndex;
    //给实例字段编号，防止因继承关系而混乱
    int slotId ;

    Field(MemberInfo & memberInfo,JClass & jClass);

    bool isPublic()  ;

    bool isPrivate()  ;

    bool isProtected()  ;

    bool isStatic()  ;

    bool isFinal()  ;

    bool isSynthetic() ;

    std::string getName()  ;

    std::string getDescriptor();

    JClass getClass();

    // jvms 5.4.4
    bool isAccessibleTo(JClass & other) ;

    bool isVolatile()  ;

    bool isTransient()  ;

    bool isEnum()  ;

    bool isLongOrDouble();

    int getConstValueIndex();

    int getSlotId();

};


#endif //FIELD_H
