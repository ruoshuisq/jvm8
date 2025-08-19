//
// Created by stephensdesktop on 2025/7/30.
//

#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#pragma once
#include <string>
#include "../util/BasicType.h"

class Field;
class Method;
class JClass;
class ConstantPoolRun;

class Constant {
private:

public:
    int type;

    ~Constant() {
    }

    void castData(char *data) {
    }

    int getType() {
        return type;
    }

    std::string getString() {return "";}
};

class ConstantInteger : public Constant {
private:
    int val;

public:
    ConstantInteger() {
        type = CONSTANT_Integer;
    }

    void castData(char *data);

    int getValue();

    std::string getString() {
        return std::to_string(val);
    }
};

class ConstantFloat : public Constant {
private:
    float val;

public:
    ConstantFloat() {
        type = CONSTANT_Float;
    }

    void castData(char *data);

    float getValue();
    std::string getString() {
        return std::to_string(val);
    }
};

class ConstantLong : public Constant {
private:
    long val;

public:
    ConstantLong() {
        type = CONSTANT_Long;
    }

    void castData(char *data);

    long getValue();
    std::string getString() {
        return std::to_string(val);
    }
};

class ConstantDouble : public Constant {
private:
    double val;

public:
    ConstantDouble() {
        type = CONSTANT_Double;
    }

    void castData(char *data);

    double getValue();
    std::string getString() {
        return std::to_string(val);
    }
};

class ConstantString : public Constant {
private:
    ConstantPoolRun *constantPoolRun;
    // int stringIndex;
    std::string str;

public:
    ConstantString() {
        type = CONSTANT_String;
    }

    void castData(char *data);

    std::string *getValue();

    void setConstantPoolRun(ConstantPoolRun &constantPoolRun);
    std::string getString() {
        return str;
    }
};

class ConstantUtf8 : public Constant {
private:
    std::string str;

public:
    ConstantUtf8() {
        type = CONSTANT_Utf8;
    }

    void castData(char *data);

    std::string *getValue();
    std::string getString() {
        return str;
    }
};

class ConstantClass : public Constant {
public:
    // used to access runtime constant pool
    ConstantPoolRun *constantPoolRun; //存放符号引用所在的运行时常量池指针
    // fully qualified name
    std::string className; //存放类的完全限定名
    // resolved class
    JClass *jClass; //缓存解析后的类结构体指针
    ConstantClass() {
        type = CONSTANT_Class;
    }

    void castData(char *data);

    std::string *getValue();

    void setConstantPoolRun(ConstantPoolRun &constantPoolRun);

    void setJClass(JClass &jClass);

    void resolvedClass();

    // jvm规范 5.4.3.1 类符号引用解析步骤
    // 如果类D通过符号引用N引用类C的话，要解析N，先用D的类加载器加载C，然后检查D是否有权限访问C，如果没有，则抛出IllegalAccessError异常。
    // 也就是说，如果类D想访问类C，需要满足两个条件之一：C是public，或者C和D在同一个运行时包内
    void resolveClassRef();

    std::string getString() {
        return className;
    }
};

class ConstantNameAndType : public ConstantClass {
public:
    std::string name;
    std::string descriptor;

    void setClassName(std::string &className) {
        this->className = className;
    }

    void setName(std::string &name) {
        this->name = name;
    }

    void setDescriptor(std::string &descriptor) {
        this->descriptor = descriptor;
    }

    std::string *getClassName() {
        return &className;
    }

    std::string *getName() {
        return &name;
    }

    std::string *getDescriptor() {
        return &descriptor;
    }

    std::string getString() {
        return name;
    }
};


class ConstantField : public ConstantNameAndType {
public:
    Field *field;

    //jvm规范 5.4.3.1 字段符号引用的解析步骤
    void resolvedField();

    void resolveFieldRef();

    std::string getString() {
        return name;
    }
};

class ConstantMethod : public ConstantNameAndType {
public:
    Method *method;
    std::string getString() {
        return name;
    }
};

class ConstantInterface : public ConstantNameAndType {
public:
    Method *method;
    std::string getString() {
        return className;
    }
};


#endif //CONSTANT_HPP
