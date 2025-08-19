//
// Created by zj on 2025/7/15.
//

#include "ClassReader.h"
#include <WinSock2.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
/**
 * 根据路径读取.class文件
 */
ClassReader *ClassReader::readByPath(std::string path) {
  FILE *fp = fopen(path.c_str(), "r"); // c++ 流的操作
  fseek(fp, 0, SEEK_END);
  char *c = new char[ftell(fp)]; // ftell(fp)函数可获取此文件字节个数 ，
                                 // 然后申请count个字节的内存空间
  int cur = 0;
  fseek(fp, 0, 0);
  // 下面将流中的字节复制到自己申请的内存中
  while (1) {
    unsigned char s = fgetc(fp);
    *(c + cur) = s;
    cur++;
    if (feof(fp)) {
      break;
    }
  }
  return new ClassReader(c); // 返回一个ClassReader对象
}

/**
 * 往后读取一个字节
 */
u1 ClassReader::readU1() {
  unsigned char *res = (unsigned char *)(data + cur);
  cur++;
  // printf("%x\n", *res);
  return (*res);
}
/**
 * 往后读取2个字节
 */
u2 ClassReader::readU2() {
  unsigned short *res = (unsigned short *)(data + cur);
  cur = cur + 2;
  // printf("%x\n",htons(*res));
  return htons(*res);
}
/**
 * 往后n个u2数组，n数量为u2，等于后面第一个u2值
 * @return
 */
u2 *ClassReader::readU2s() {
  u2 read_u2 = readU2();
  u2 rs[read_u2];
  for (int i = 0; i < read_u2; i++) {
    rs[i] = readU2();
  }
  return rs;
}
/**
 * 往后读取4个字节
 */
u4 ClassReader::readU4() {
  int *res = (int *)(data + cur);
  cur = cur + 4;
  // printf("%x\n",htons(*res));
  return htonl(*res);
}
/**
 * 往后读取8个字节
 */
u8 ClassReader::readU8() {
  int *res = (int *)(data + cur);
  cur = cur + 8;
  // printf("%x\n",htons(*res));
  return htonl(*res);
}
/**
 * 往后读取n个字节，并把值赋给target
 */
void ClassReader::readUn(u2 n, char *target) {
  for (int i = 0; i < n; i++) {
        target[i] = readU1();
    }
    target[n] = '\0';
}

ClassReader::ClassReader(char *data) : data(data) {}//构造方法