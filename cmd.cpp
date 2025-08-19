//
// Created by zj on 2025/7/11.
//

#include "cmd.h"
#include <stdio.h>
#include <vector>
int parseCmd(Cmd cmd) {
    //TODO写死
    cmd.helpFlag=false;
    cmd.versionFlag=false;
//    cmd.cpOption="";//classPath
//    cmd.klass="";//main class主方法
//    cmd.XjreOption="C:/work/java/jdk/jdk1.8.0_131/jre" ;//指定jre目录的位置
//    cmd.args={"1","2","3"};//主方法的args参数
    return 0;
}

void printUsage() {
    printf("Usage: myjava [-option] class [args]\n");
}
