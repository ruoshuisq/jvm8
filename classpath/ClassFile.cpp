//
// Created by zj on 2025/7/18.
//

#include "ClassFile.h"

#include <winsock2.h>


//void readAndCheckMagic(ClassReader &cr, ClassFileST &class_file_st_) {
//  u4 magic = cr.readU4();
//  if (magic != 0xCAFEBABE) {
//    printf("java.lang.ClassFormatError: magic!");
//    return;
//  }
//  class_file_st_.magic = magic;
//}
//void readAndCheckVersion(ClassReader &reader, ClassFileST &class_file_st_) {
//  class_file_st_.minorVersion = reader.readU2();
//  class_file_st_.majorVersion = reader.readU2();
//  switch (class_file_st_.majorVersion) {
//  case 45:
//    return;
//  case 46:
//  case 47:
//  case 48:
//  case 49:
//  case 50:
//  case 51:
//  case 52:
//    if (class_file_st_.minorVersion == 0) {
//      return;
//    }
//  }
//
//  printf("java.lang.UnsupportedClassVersionError!");
//}

void readAndCheckMagic(ClassReader &cr, ClassFile &class_file) {
  u4 magic = cr.readU4();
  if (magic != 0xCAFEBABE) {
    printf("java.lang.ClassFormatError: magic!");
    return;
  }
  class_file.magic = magic;
}
void readAndCheckVersion(ClassReader &reader, ClassFile &class_file) {
  class_file.minorVersion = reader.readU2();
  class_file.majorVersion = reader.readU2();
  switch (class_file.majorVersion) {
  case 45:
    return;
  case 46:
  case 47:
  case 48:
  case 49:
  case 50:
  case 51:
  case 52:
    if (class_file.minorVersion == 0) {
      return;
    }
  }

  printf("java.lang.UnsupportedClassVersionError!");
}


void readConstantPool(ClassReader &reader,ConstantPool &constant_pool) {
  u2 cpCount = reader.readU2();
  constant_pool.tags = std::map<int, int>();
  for (int i = 1; i < cpCount; i++) {
    u1 tag = reader.readU1();
    constant_pool.tags[i]=tag;
    switch (tag) {
    case CONSTANT_Utf8: {
      u2 len = reader.readU2(); // 读两个字节作为utf-8的字节长度
      char *target =
          new char[len +1]; // 申请len+1长度的字节内存，c语言最后一位需要用'\0'填充
      reader.readUn(len, target);       // 读取len个字节
      (constant_pool.data[i]) = target; // 存储在常量池
      printf("第%d个，类型utf-8，值%s\n", i, constant_pool.data[i]);
      break;
    }
    case CONSTANT_Integer: {
      u4 temp = reader.readU4();      // 读取四个字节
      char *charTmp=new char[4] ; // 存储在常量池
      itoa(temp,charTmp,10);
      constant_pool.data[i] = charTmp; // 存储在常量池
      printf("第%d个，类型Integer，值%d\n", i, *constant_pool.data[i]);
      break;
    }
    case CONSTANT_Float: {
      u4 temp = reader.readU4();      // 读取四个字节
      char *charTmp=new char[4] ; // 存储在常量池
      itoa(temp,charTmp,10);//todo 有问题
      constant_pool.data[i] = charTmp; // 存储在常量池
      printf("第%d个，类型Float，值%d\n", i, *constant_pool.data[i]);
      break;
    }
    case CONSTANT_Long: {
      u8 temp  = reader.readU8();      // 读取8个字节
      char *charTmp=new char[8] ; // 存储在常量池
      ltoa(temp,charTmp,10);
      constant_pool.data[i] = charTmp; // 存储在常量池
      printf("第%d个，类型Long，值%d\n", i, *constant_pool.data[i]);
      break;
    }
    case CONSTANT_Double: {
      u8 temp = reader.readU8();      // 读取8个字节
      char *charTmp=new char[8] ; // 存储在常量池
      ltoa(temp,charTmp,10);
      constant_pool.data[i] = charTmp; // 存储在常量池
      printf("第%d个，类型Double，值%d\n", i, *constant_pool.data[i]);
      break;
    }
    case CONSTANT_Class: {
      u2 temp = reader.readU2();      // 读取两个字节
      char *charTmp=new char[2] ; // 存储在常量池
      itoa(temp,charTmp,10);
      constant_pool.data[i] = charTmp; // 存储在常量池
      printf("第%d个，类型Class，值%d\n", i, *constant_pool.data[i]);
      break;
    }
    case CONSTANT_String: {
      u2 temp = reader.readU2();      // 读取两个字节
      char *charTmp=new char[2] ; // 存储在常量池
      itoa(temp,charTmp,10);
      constant_pool.data[i] = charTmp; // 存储在常量池
      printf("第%d个，类型std::string，值%d\n", i, *constant_pool.data[i]);
      break;
    }
    case CONSTANT_Fieldref:
    case CONSTANT_Methodref:
    case CONSTANT_InterfaceMethodref: {
      int *temp = new int;                      // 申请四个字节的内存空间
      short classIndex = reader.readU2();       // 读取两个字节
      short nameAndTypeIndex = reader.readU2(); // 读取两个字节
      //小端转大端，即主机转网络
      *temp = htonl(
          classIndex << 16 |
          nameAndTypeIndex); // 左16位存储classIndex 右16为存储nameAndTypeIndex
      int size =sizeof (temp)*2;
      char*  charTemp=new char[size];
      ltoa(*temp,charTemp,10);
      (constant_pool.data[i]) = charTemp; // 存储在常量池
      printf("第%d个，类型file、method、Interface Methodref，值%d and %d \n", i,
             classIndex,nameAndTypeIndex);
      break;
    }
    case CONSTANT_NameAndType: {
      int *temp = new int;
      short nameIndex = reader.readU2();       // 读取两个字节
      short descriptorIndex = reader.readU2(); // 读取两个字节
      *temp = htonl(
          nameIndex << 16 |
          descriptorIndex); // 左16位存储classIndex 右16为存储nameAndTypeIndex
      int size =sizeof (temp)*2;
      char*  charTemp=new char[size];
      ltoa(*temp,charTemp,10);
      (constant_pool.data[i]) = charTemp; // 存储在常量池
      printf("第%d个，类型NameAndType，值%X\n", i,
             htonl(*(int *)constant_pool.data[i]));
      break;
    }
    case CONSTANT_MethodHandle: {
      int *temp = new int;
      short referenceKind = reader.readU1();       // 读取1个字节
      short referenceIndex = reader.readU2(); // 读取两个字节
      *temp = htonl(
          referenceKind << 16 |
          referenceIndex); // 左8位存储referenceKind 右16为存储referenceIndex
      int size =sizeof (temp)*2;
      char*  charTemp=new char[size];
      ltoa(*temp,charTemp,10);
      (constant_pool.data[i]) = charTemp; // 存储在常量池
      printf("第%d个，类型MethodHandle，值%X\n", i,
             htonl(*(int *)constant_pool.data[i]));
      break;
    }
    case CONSTANT_MethodType: {
      u2 temp = reader.readU2();      // 读取两个字节
      char *charTmp=new char[2] ; // 存储在常量池
      itoa(temp,charTmp,10);
      constant_pool.data[i] = charTmp; // 存储在常量池
      printf("第%d个，类型MethodType，值%d\n", i, *constant_pool.data[i]);
      break;
    }
    case CONSTANT_InvokeDynamic: {
      int *temp = new int;
      short bootstrapMethodAttrIndex = reader.readU2();       // 读取两个字节
      short nameAndTypeIndex = reader.readU2(); // 读取两个字节
      *temp = htonl(
          bootstrapMethodAttrIndex << 16 |
          nameAndTypeIndex); // 左16位存储classIndex 右16为存储nameAndTypeIndex
      int size =sizeof (temp)*2;
      char*  charTemp=new char[size];
      ltoa(*temp,charTemp,10);
      (constant_pool.data[i]) = charTemp; // 存储在常量池
      printf("第%d个，类型InvokeDynamic，值%X\n", i,
             htonl(*(int *)constant_pool.data[i]));
      break;
    }

    default:
      break;
    }
  }
}

void readMembers(ClassReader &reader, ConstantPool &constP,std::map<int,MemberInfo> &member_infos,int count) {
  for (int i=0;i<count;i++) {
    auto member_info=new MemberInfo;
    MemberInfoST *memberInfoSt=new MemberInfoST();
    member_info->member_info_st_=memberInfoSt;
    member_info->readMember(reader, constP);
//    member_infos[i]->insert(std::make_pair(i, member_info));
//    member_infos->insert(std::map<const int, MemberInfo>::value_type(i, member_info));
    member_infos[i] = *member_info;
  }
}

void readAttributeInfos(ClassReader &reader,ConstantPool &constant_pool,std::map<int,AttributeInfo> &attribute_infos,int count) {
  for (int i=0;i<count;i++) {
    AttributeInfo *attribute_info=new AttributeInfo();
    attribute_info->readAttributeInfo(reader, constant_pool);
    attribute_infos[i]=*attribute_info;
  }
}
//ClassFile::ClassFile(ClassFileST *class_file_st_) : class_file_st_(class_file_st_) {
//  this->class_file_st_=class_file_st_;
//  this->class_file_st_->constantPool=new ConstantPool();
//} // 构造方法
void ClassFile::parse(ClassReader &cr) {
  readAndCheckMagic(cr, *this);
  readAndCheckVersion(cr, *this);
  //读取常量池
  this->constantPool=new ConstantPool();
  readConstantPool(cr,*this->constantPool);
  this->accessFlags = cr.readU2();
  //类索引
  this->thisClass = cr.readU2();
  //超类索引
  this->superClass = cr.readU2();
  //接口索引表，列表存的是常量池索引，即索引列表，而不是字符串列表
  this->interfaces = cr.readU2s();
  //字段
  u2 fieldsCount = cr.readU2();
  this->fieldCount=fieldsCount;
  if(fieldsCount>0) {
    if(this->fields== nullptr){
      std::map<int,MemberInfo> * fields=new std::map<int,MemberInfo>();
      this->fields=fields;
    }
    readMembers(cr, *this->constantPool,*this->fields,fieldsCount);
  }
  //方法
  u2 methodsCount = cr.readU2();
  this->methodsCount=methodsCount;
  if(methodsCount>0) {
    if(this->methods== nullptr){
      std::map<int,MemberInfo> * methods=new std::map<int,MemberInfo>();
      this->methods=methods;
    }
    readMembers(cr, *this->constantPool,*this->methods,methodsCount);
  }
  //属性
  u2 attributeCount = cr.readU2();
  this->attributesCount=attributeCount;
  if(attributeCount>0) {
    if(this->attributes== nullptr){
      std::map<int,AttributeInfo> * attributes=new std::map<int,AttributeInfo>();
      this->attributes=attributes;
    }
    readAttributeInfos(cr, *this->constantPool,
                       *this->attributes, attributeCount);
  }

}

u1 ClassFile::MinorVersion() { return this->minorVersion; }
u1 ClassFile::MajorVersion() { return this->majorVersion; }
ConstantPool ClassFile::getConstantPool() { return *this->constantPool; }
u1 ClassFile::AccessFlags() { return this->accessFlags; }
std::map<int,MemberInfo> ClassFile::Fields() { return *this->fields; }
std::map<int,MemberInfo> ClassFile::Methods() {
  return *this->methods;
}
std::string ClassFile::ClassName() {
  return (this->constantPool)->getStringFromPool(this->thisClass);
}

std::string ClassFile::SuperClassName() {
  if (this->superClass > 0) {
    return (this->constantPool)->getStringFromPool(this->superClass);
  }
  return "";
}

void ClassFile::InterfaceNames(std::map<int,std::string> & interfaceNames) {
  if(this->interfaces==nullptr) {
    return;
  }
  size_t size = sizeof(this->interfaces) / 2;
  for (int i=0;i<size;i++) {
    interfaceNames[i] = (this->constantPool)->getStringFromPool(this->interfaces[i]);
  }
}