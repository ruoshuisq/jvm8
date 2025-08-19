//
// Created by stephensdesktop on 2025/7/30.
//


#include "ClassLoader.hpp"

#include "Constant.hpp"
#include "../classpath/ClassPathEntry.h"
#include "JClass.hpp"
#include "Field.hpp"
#include "Constant.hpp"
#include "ConstantPoolRun.hpp"
#include "../LocalVars.h"
#include "../classpath/ClassFile.h"
#include "../Solt.hpp"


ClassLoader::ClassLoader(ClassPathEntry &class_path_entry) {
    this->classPathEntry = &class_path_entry;
    this->classMap=new std::map<std::string, JClass>();
}

//把类数据加载到方法区
JClass *ClassLoader::loadClass(std::string className) {
    //是否已经加载，已经加载直接返回
    std::map<std::string, JClass>::iterator iter = classMap->find(className);
    if (iter != classMap->end()) {
        return &iter->second;
    }
    // 数组类和普通类有很大的不同，它的数据并不是来自class文件，而是由Java虚拟机在运行期间生成。
    return loadNonArrayClass(className);
}

JClass *ClassLoader::loadNonArrayClass(std::string className) {
    // load data to memory 首先找到class文件并把数据读取到内存
    char *data = readClass(className);
    // parse and put in method area 解析class文件，生成虚拟机可以使用的类数据，并放入方法区
    JClass *jClass = defineClass(data);
    // link 链接
    link(*jClass);
}

char *ClassLoader::readClass(std::string className) {
    Entry entry = classPathEntry->readClass(className);
    return entry.data;
}

// parse and put in method area 解析class文件，生成虚拟机可以使用的类数据，并放入方法区
JClass *ClassLoader::defineClass(char *data) {
    //把class文件数据转换成Class结构体
    JClass *jClass = parseClass(data);
    jClass->loader = this;
    //解析这些类符号引用
    resolveSuperClass(*jClass);
    resolveInterfaces(*jClass);
    //插入不是覆盖TODO
    classMap->insert(std::pair<std::string, JClass>(jClass->name, *jClass));
}

JClass *ClassLoader::parseClass(char *data) {
    ClassFile *class_file = new ClassFile();
    ClassReader class_reader = ClassReader(data);
    class_file->parse(class_reader);
    JClass *jClass = new JClass(*class_file);
    return jClass;
}

// 链接分为验证和准备两个必要阶段
void ClassLoader::link(JClass &jClass) {
    //验证
    verify(jClass);
    //准备阶段主要是给类变量分配空间并给予初始值
    prepare(jClass);
}

void ClassLoader::verify(JClass &jClass) {
    // TODO IMPL
    // Java虚拟机规范4.10节详细介绍了类的验证算法
    // 未实现
}

// 准备阶段主要是给类变量分配空间并给予初始值
void ClassLoader::prepare(JClass &jClass) {
    calcInstanceFieldSlotIds(jClass);
    calcStaticFieldSlotIds(jClass);
    allocAndInitStaticVars(jClass);
}

// calc the number of instance fields and give it number 计算实例字段的个数，同时给它们编号
void ClassLoader::calcInstanceFieldSlotIds(JClass &jClass) {
    int slotId = 0;
    if (jClass.superClass != nullptr) {
        slotId = jClass.superClass->instanceSlotCount;
    }
    std::map<int, Field> fields = *jClass.fields;
    for (auto pair : fields) {
        Field field = pair.second;
        if (!field.isStatic()) {
            field.slotId = slotId;
            slotId++;
            if (field.isLongOrDouble()) {
                slotId++;
            }
        }
    }
    jClass.instanceSlotCount = slotId;
}

// 计算静态字段的个数，同时给它们编号
void ClassLoader::calcStaticFieldSlotIds(JClass &jClass) {
    int slotId = 0;
    std::map<int, Field> fields = *jClass.fields;
    for (auto pair : fields) {
        Field field = pair.second;
        if (field.isStatic()) {
            field.slotId = slotId;
            slotId++;
            if (field.isLongOrDouble()) {
                slotId++;
            }
        }
    }
    jClass.staticSlotCount = slotId;
}

// 给类变量分配空间，然后给它们赋予初始值
void ClassLoader::allocAndInitStaticVars(JClass &jClass) {
    jClass.staticVars = new std::map<int, Solt>();
    std::map<int, Field> fields = *jClass.fields;
    for (auto pair : fields) {
        Field field =pair.second;
        if (field.isStatic() && field.isFinal()) {
            initStaticFinalVar(jClass, field);
        }
    }
    // for (int i = 0; i < fields.size(); i++) {
    //     Field field = fields[i];
    //     if (field.isStatic() && field.isFinal()) {
    //         initStaticFinalVar(jClass, field);
    //     }
    // }
}

// 从常量池中加载常量值，然后给静态变量赋值。
// 静态变量属于基本类型或String类型，有final修饰符，且它的值在编译期已知，则该值存储在class文件常量池中
void ClassLoader::initStaticFinalVar(JClass &jClass, Field &field) {
    std::map<int, Solt> pairs = *jClass.staticVars;
    ConstantPoolRun *constant_pool_run = jClass.constantPoolRun;
    int const_value_index = field.constValueIndex;
    int slotId = field.slotId;

    if (const_value_index > 0) {
        switch (hash_compile_time(field.getDescriptor().data())) {
            case "Z"_hash "B"_hash "C"_hash "S"_hash "I"_hash: {
                Constant *constant = constant_pool_run->getConstant(const_value_index);
                ConstantInteger *constantInteger = static_cast<ConstantInteger *>(constant);
                pairs[slotId].byte4Int = constantInteger->getValue();
            }

            case "J"_hash: {
                Constant *constant = constant_pool_run->getConstant(const_value_index);
                ConstantLong *constantLong = static_cast<ConstantLong *>(constant);
                pairs[slotId].byte8Long = constantLong->getValue();
            }
            case "F"_hash: {
                Constant *constant = constant_pool_run->getConstant(const_value_index);
                ConstantFloat *constantFloat = static_cast<ConstantFloat *>(constant);
                pairs[slotId].byte4Float = constantFloat->getValue();
            }
            case "D"_hash: {
                Constant *constant = constant_pool_run->getConstant(const_value_index);
                ConstantDouble *constantDouble = static_cast<ConstantDouble *>(constant);
                pairs[slotId].byte8Double = constantDouble->getValue();
            }
            case "Ljava/lang/String;"_hash:
                ; //TODO
        }
    }
}

// recursion 除非是Object类，否则需要递归调用LoadClass（）方法加载它的超类
void ClassLoader::resolveSuperClass(JClass &jClass) {
    if (strcmp("java/lang/Object", jClass.name.data()) != 0) {
        jClass.superClass = jClass.loader->loadClass(jClass.superClassName);
    }
}

// 递归调用
void ClassLoader::resolveInterfaces(JClass &jClass) {
    auto pairs = *jClass.interfaceNames;
    auto interfaces = jClass.interfaces;
    int interfaceCount = pairs.size();
    for (int i = 0; i < interfaceCount; i++) {
         JClass load_class = *jClass.loader->loadClass(pairs[i]);
        interfaces->insert(std::pair<int, JClass>(i, load_class));
    }
}
