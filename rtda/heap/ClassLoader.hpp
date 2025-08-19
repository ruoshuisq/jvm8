//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef CLASSLOADER_HPP
#define CLASSLOADER_HPP

#pragma once
#include <map>
#include <string>


class Field;
class ClassPathEntry;
class JClass;

class ClassLoader {
private:
    ClassPathEntry *classPathEntry;
    std::map<std::string, JClass>* classMap;

public:
    ClassLoader(ClassPathEntry &class_path_entry);

    //把类数据加载到方法区
    JClass *loadClass(std::string className);

    JClass *loadNonArrayClass(std::string className);

    char *readClass(std::string className);

    // parse and put in method area 解析class文件，生成虚拟机可以使用的类数据，并放入方法区
    JClass *defineClass(char *data);

    JClass *parseClass(char *data);

    // 链接分为验证和准备两个必要阶段
    void link(JClass &jClass);

    void verify(JClass &jClass);

    // 准备阶段主要是给类变量分配空间并给予初始值
    void prepare(JClass &jClass);

    // calc the number of instance fields and give it number 计算实例字段的个数，同时给它们编号
    void calcInstanceFieldSlotIds(JClass &jClass);

    // 计算静态字段的个数，同时给它们编号
    void calcStaticFieldSlotIds(JClass &jClass);

    // 给类变量分配空间，然后给它们赋予初始值
    void allocAndInitStaticVars(JClass &jClass);

    // 从常量池中加载常量值，然后给静态变量赋值。
    // 静态变量属于基本类型或String类型，有final修饰符，且它的值在编译期已知，则该值存储在class文件常量池中
    void initStaticFinalVar(JClass &jClass, Field &field);

    // recursion 除非是Object类，否则需要递归调用LoadClass（）方法加载它的超类
    void resolveSuperClass(JClass &jClass);

    // 递归调用
    void resolveInterfaces(JClass &jClass);
};


#endif //CLASSLOADER_HPP
