//
// Created by zj on 2025/7/19.
//

#include "MemberInfo.h"

MemberInfo::MemberInfo() {
  count=0;
}

void MemberInfo::readAttributeInfos(ClassReader &reader,ConstantPool &constant_pool,std::map<int,AttributeInfo> &attribute_infos,int count) {

  for (int i=0;i<count;i++) {
    AttributeInfo *attribute_info=new AttributeInfo();
    attribute_info->readAttributeInfo(reader, constant_pool);
    attribute_infos[i]=*attribute_info;
  }
}

void MemberInfo::readMember(ClassReader &reader, ConstantPool &constP) {
  u2 accessFlags = reader.readU2();
  u2 nameIndex = reader.readU2();
  u2 descriptorIndex = reader.readU2();
  member_info_st_->accessFlags = accessFlags;
  member_info_st_->nameIndex = nameIndex;
  member_info_st_->descriptorIndex = descriptorIndex;
  member_info_st_->constP=&constP;
  //属性
  u2 attributeCount = reader.readU2();
  if(attributeCount>0) {
    readAttributeInfos(reader, constP,member_info_st_->attributes,attributeCount);
  }
  count=nameIndex;
}

std::string MemberInfo::Name() {
  return member_info_st_->constP->getStringFromPool(member_info_st_->nameIndex);
}
std::string MemberInfo::Descriptor() {
  return member_info_st_->constP->getStringFromPool(member_info_st_->descriptorIndex);
}
std::optional<std::reference_wrapper<AttributeInfo>> MemberInfo::getCodeAttributeInfo(){
  std::optional<std::reference_wrapper<AttributeInfo>> att;
      for (auto &pair : member_info_st_->attributes) {
        if(pair.second.getCodeAttribute().code != nullptr){
          return std::optional<std::reference_wrapper<AttributeInfo>> (pair.second);
        }
  }
  return std::nullopt;
}
int MemberInfo::getCount() { return count; }

