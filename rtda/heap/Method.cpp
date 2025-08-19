//
// Created by stephensdesktop on 2025/7/29.
//


#include "Method.hpp"
#include "JClass.hpp"

Method::Method(MemberInfo & memberInfo, JClass & jClass) {
    this->name = memberInfo.Name();
    this->accessFlags = memberInfo.member_info_st_->accessFlags;
    this->descriptor = memberInfo.Descriptor();
    this->jClass = &jClass;
    for (std::pair<const int, AttributeInfo> attribute : memberInfo.member_info_st_->attributes) {
        this->maxLocals=attribute.second.getCodeAttribute().maxLocals;
        this->maxStack=attribute.second.getCodeAttribute().maxStack;
        this->code=attribute.second.getCodeAttribute().code;
    }
}

bool Method::isPublic() {
    return this->accessFlags & ACC_PUBLIC != 0;
}

bool Method::isPrivate() {
    return this->accessFlags & ACC_PRIVATE != 0;
}

bool Method::isProtected() {
    return this->accessFlags & ACC_PROTECTED != 0;
}

bool Method::isStatic() {
    return this->accessFlags & ACC_STATIC != 0;
}

bool Method::isFinal() {
    return this->accessFlags & ACC_FINAL != 0;
}

bool Method::isSynthetic() {
    return this->accessFlags & ACC_SYNTHETIC != 0;
}

std::string Method::getName() {
    return this->name;
}

std::string Method::getDescriptor() {
    return this->descriptor;
}

JClass Method::getClass() {
    return *this->jClass;
}

// jvms 5.4.4
bool Method::isAccessibleTo(JClass &other) {
    if (this->isPublic()) {
        return true;
    }
    JClass thisClass = this->getClass();
    JClass *thisClassP = &thisClass;
    JClass *otherP = &other;
    if (this->isProtected()) {
        return otherP == thisClassP ||
               thisClass.getPackageName() == other.getPackageName();
    }
    if (!this->isPrivate()) {
        return thisClass.getPackageName() == other.getPackageName();
    }
    return otherP == thisClassP;
}

bool Method::isSynchronized(){return this->accessFlags & ACC_SYNCHRONIZED != 0;
}

bool Method::isBridge(){
return this->accessFlags & ACC_BRIDGE != 0;}

bool Method::isVarargs(){
    return this->accessFlags & ACC_VARARGS != 0;}

bool Method::isNative(){
    return this->accessFlags & ACC_NATIVE != 0;}

bool Method::isAbstract(){
    return this->accessFlags & ACC_ABSTRACT != 0;}

bool Method::isStrict(){
    return this->accessFlags & ACC_STATIC != 0;}

int  Method::getMaxStack() {
    return maxStack;
}

int  Method::getMaxLocals(){
return maxLocals;
}

char* Method::getCode() {
    return code;
}