//
// Created by zj on 2025/7/25.
//

#ifndef CONSTANTSTEST_H
#define CONSTANTSTEST_H
#include "../rtda/interpret.h"


class ConstantsTest {

};

void testConstant0(CodeAttribute code_attribute_) {
  std::string *args=new std::string[2];
  args[0]="1";
  args[1]="2";
  char*data="0x030x030x03";
  code_attribute_.code=data;
  run( code_attribute_,args);
}


#endif //CONSTANTSTEST_H
