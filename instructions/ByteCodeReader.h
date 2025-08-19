//
// Created by zj on 2025/7/25.
//

#ifndef ByteCodeReader_H
#define ByteCodeReader_H

#include "../util/BasicType.h"

#include <winsock2.h>

class ByteCodeReader {
private:
  char *data;
  int pc = 0;

public:
  /**
 * 往后读取一个字节
 */
  u1 readU1() {
    unsigned char *res = (unsigned char *)(data + pc);
    pc++;
    // printf("%x\n", *res);
    return (*res);
  }
  /**
 * 往后读取一个字节
   */
  s1 readS1() {
    s1 *res = (s1 *)(data + pc);
    pc++;
    // printf("%x\n", *res);
    return (*res);
  }
  /**
   * 往后读取2个字节
   */
  u2 readU2() {
    unsigned short *res = (unsigned short *)(data + pc);
    pc = pc + 2;
    // printf("%x\n",htons(*res));
    return htons(*res);
  }
  /**
   * 往后读取2个字节
   */
  s2 readS2() {
    s2 *res = ( s2 *)(data + pc);
    pc = pc + 2;
    // printf("%x\n",htons(*res));
    return htons(*res);
  }
  /**
   * 往后n个u2数组，n数量为u2，等于后面第一个u2值
   * @return
   */
  u2 *readU2s() {
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
  u4 readU4() {
    u2 *res = (u2 *)(data + pc);
    pc = pc + 4;
    // printf("%x\n",htons(*res));
    return htonl(*res);
  }
  /**
   * 往后读取4个字节
   */
  s4 readS4() {
    s4 *res = (s4 *)(data + pc);
    pc = pc + 4;
    // printf("%x\n",htons(*res));
    return htonl(*res);
  }
  /**
   * 往后n个u4数组，n数量为u4，等于后面第一个u4值
   * @return
   */
  void readU4s(int n,int rs[]) {
    for (int i = 0; i < n; i++) {
      rs[i] = readU4();
    }
  }
  /**
   * 往后读取8个字节
   */
  u8 readU8() {
    int *res = (int *)(data + pc);
    pc = pc + 8;
    // printf("%x\n",htons(*res));
    return htonl(*res);
  }
  /**
   * 往后读取n个字节，并把值赋给target
   */
  void readUn(short n, char *target) {
    for (int i = 0; i < n; i++) {
      target[i] = readU1();
    }
    target[n] = '\0';
  }

  int getPC()  {
    return this->pc;
  }

  void reset(char*data,int pc ) {
//    this->data = data;
    this->pc = pc;
  }
  void skipPadding() {
    do {
      this->readU1();
    }while (this->pc%4!=0);
  }
  ByteCodeReader(char *data) : data(data) {}//构造方法
};


#endif //ByteCodeReader_H
