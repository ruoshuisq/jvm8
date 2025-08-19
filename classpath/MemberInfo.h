//
// Created by zj on 2025/7/19.
//

#ifndef MEMBERINFO_H
#define MEMBERINFO_H
#include "AttributeInfo.h"
#include "ClassReader.h"
#include "ConstantPool.h"

#include <optional>
#include <vector>

struct MemberInfoST {
  u2 accessFlags;
  u2 nameIndex;
  u2 descriptorIndex;
  ConstantPool* constP;
  std::map<int,AttributeInfo> attributes;
};

class MemberInfo {
private:
  int count;
public:
  MemberInfoST* member_info_st_;
  MemberInfo();
  void readMember(ClassReader &reader, ConstantPool &constP) ;
  void readAttributeInfos(ClassReader &reader,ConstantPool &constant_pool,std::map<int,AttributeInfo> &attribute_infos,int count);
  std::string Name();
  std::string Descriptor();
  std::optional<std::reference_wrapper<AttributeInfo>> getCodeAttributeInfo();
  int getCount();
};

#endif //MEMBERINFO_H
