//
// Created by zj on 2025/7/22.
//

#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include <map>

#include "JClass.hpp"


class Solt;
class Object {
public:
    JClass * jClass;
    //实例变量
    std::map<int,Solt>* fields;
    int instanceSlotCount;

    bool isInstanceOf(JClass jClass);
};



#endif //OBJECT_H
