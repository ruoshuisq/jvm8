//
// Created by stephensdesktop on 2025/7/29.
//


#include "Field.hpp"

#include <string.h>
#include "../classpath/AttributeInfo.h"
#include "JClass.hpp"
#include "ClassLoader.hpp"


Field::Field(MemberInfo & memberInfo,JClass & jClass) {
    this->name = memberInfo.Name();
    this->accessFlags = memberInfo.member_info_st_->accessFlags;
    this->descriptor = memberInfo.Descriptor();
    this->jClass = &jClass;
    for (std::pair<const int, AttributeInfo> attribute : memberInfo.member_info_st_->attributes) {
        this->constValueIndex=attribute.second.getConstantValueAttribute().constantValueIndex;
    }
}

bool Field::isPublic() {
    return this->accessFlags & ACC_PUBLIC != 0;
}

bool Field::isPrivate() {
    return this->accessFlags & ACC_PRIVATE != 0;
}

bool Field::isProtected() {
    return this->accessFlags & ACC_PROTECTED != 0;
}

bool Field::isStatic() {
    return this->accessFlags & ACC_STATIC != 0;
}

bool Field::isFinal() {
    return this->accessFlags & ACC_FINAL != 0;
}

bool Field::isSynthetic() {
    return this->accessFlags & ACC_SYNTHETIC != 0;
}

std::string Field::getName() {
    return this->name;
}

std::string Field::getDescriptor() {
    return this->descriptor;
}

JClass Field::getClass() {
    return *this->jClass;
}

// jvms 5.4.4
bool Field::isAccessibleTo(JClass &other) {
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

bool Field::isVolatile() {
    return this->accessFlags & ACC_VOLATILE != 0;
}

bool Field::isTransient() {
    return this->accessFlags & ACC_TRANSIENT != 0;
}

bool Field::isEnum() {
    return this->accessFlags & ACC_ENUM != 0;
}

bool Field::isLongOrDouble() {
    return strcmp(this->descriptor.data(), "J") == 0 || strcmp(this->descriptor.data(), "D") == 0;
}

int Field::getConstValueIndex() {
    return this->constValueIndex;
}

int Field::getSlotId() {
    return this->slotId;
}
