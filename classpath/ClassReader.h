//
// Created by zj on 2025/7/15.
//

#ifndef CLASSREAD_H
#define CLASSREAD_H
#include <string>
#include "../util/BasicType.h"

class ClassReader {
    char *data;
    int cur = 0;
public:
    //构造方法
    ClassReader(char *data);

    //根据路径读取.class文件
    static ClassReader* readByPath(std::string path);

    u1 readU1();//往后读取一个字节
    u2 readU2();//往后读取两个字节
    u4 readU4();//往后读取四个字节
    u8 readU8();//往后读取8个字节
    void readUn(u2 n,char* target);//往后读取n个字节，并把值赋给target
    u2* readU2s();//往后n个u2数组，n数量为u2，等于后面第一个u2值

};



#endif //CLASSREAD_H
