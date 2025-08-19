//
// Created by zj on 2025/7/11.
//
#include <string>
#include <iostream>
#include <vector>
#ifndef CMD_H
#define CMD_H


struct Cmd {
   bool helpFlag ;
   bool versionFlag;
   std::string cpOption;//classpath位置
   std::string mainClass; //主类名
   std::vector<std::string> args;//main函数的args参数
   std::string XjreOption;   // jre位置（一个非标准选项）

};

int parseCmd(Cmd cmd) ;
void printUsage();
#endif //CMD_H
