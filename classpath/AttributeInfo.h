//
// Created by zj on 2025/7/19.
//

#ifndef ATTRIBUTEINFO_H
#define ATTRIBUTEINFO_H
#include "ClassReader.h"
#include "ConstantPool.h"

#include <any>

struct BootstrapMethod {
  u2 bootstrapMethodRef;
  u2 *bootstrapArguments;
};
struct UnparsedAttribute {
  std::string name;
  u4 length;
  u1 *info;
};

struct ConstantValueAttribute {
  u2 constantValueIndex;
};

struct EnclosingMethodAttribute {
  ConstantPool *constantPool;
  u2 classIndex;
  u2 methodIndex;
};

struct ExceptionsAttribute {
  u2 *exceptionIndexTable;
};

struct InnerClassInfo {
  u2 innerClassInfoIndex;
  u2 outerClassInfoIndex;
  u2 innerNameIndex;
  u2 innerClassAccessFlags;
};
struct InnerClassesAttribute {
  InnerClassInfo *classes;
};
struct LineNumberTableEntry {
  u2 startPc;
  u2 lineNumber;
};
struct LineNumberTableAttribute {
  LineNumberTableEntry *lineNumberTable;
};
struct LocalVariableTableEntry {
  u2 startPc;
  u2 length;
  u2 nameIndex;
  u2 descriptorIndex;
  u2 index;
};
struct LocalVariableTableAttribute {
  LocalVariableTableEntry *localVariableTable;
};

struct LocalVariableTypeTableEntry {
  u2 startPc;
  u2 length;
  u2 nameIndex;
  u2 signatureIndex;
  u2 index;
};
struct LocalVariableTypeTableAttribute {
  LocalVariableTypeTableEntry* localVariableTypeTable;
};
struct MarkerAttribute {};
struct DeprecatedAttribute {
  MarkerAttribute * markerAttribute;
};

struct SyntheticAttribute {
  MarkerAttribute *markerAttribute;
};

struct SignatureAttribute {
  ConstantPool *constantPool;
  u2 signatureIndex;
};

struct SourceFileAttribute {
  ConstantPool *constantPool;
  u2 sourceFileIndex;
};
struct ExceptionTableEntry {
  u2 startPc;
  u2 endPc;
  u2 handlerPc;
  u2 catchType;
};
struct CodeAttribute {
  ConstantPool *constantPool;
  u2 maxStack;
  u2 maxLocals;
  char *code;
  ExceptionTableEntry *exceptionTable;
  LineNumberTableAttribute *lineNumberTableAttribute;
  LocalVariableTableAttribute *localVariableTableAttribute;
  LocalVariableTypeTableAttribute *localVariableTypeTableAttribute;
  UnparsedAttribute *attributes;
};

class AttributeInfo {
private:
  CodeAttribute code_attribute_;
  SourceFileAttribute source_file_attribute_;
  SignatureAttribute signature_attribute_;
  DeprecatedAttribute deprecated_attribute_;
  SyntheticAttribute synthetic_attribute_;
  LocalVariableTypeTableAttribute local_variable_type_table_attribute_;
  LocalVariableTableAttribute local_variable_table_attribute_;
  LineNumberTableAttribute line_number_table_attribute_;
  InnerClassesAttribute inner_classes_attribute_;
  ExceptionsAttribute exceptions_attribute_;
  BootstrapMethod bootstrap_method_;
  UnparsedAttribute unparsed_attribute_;
  ConstantValueAttribute constant_value_attribute_;
  EnclosingMethodAttribute enclosing_method_attribute_;

public:
  void readAttributeInfo(ClassReader &reader, ConstantPool &constant_pool);
  void setCodeAttribute(CodeAttribute code_attribute_);
  void setSourceFileAttribute(SourceFileAttribute source_file_attribute_);
  void setSignatureAttribute(SignatureAttribute signature_attribute_);
  void setDeprecatedAttribute(DeprecatedAttribute deprecated_attribute_);
  void setSyntheticAttribute(SyntheticAttribute synthetic_attribute_);
  void setLocalVariableTypeTableAttribute(
      LocalVariableTypeTableAttribute local_variable_type_table_attribute_);
  void setLocalVariableTableAttribute(
      LocalVariableTableAttribute local_variable_table_attribute_);
  void setLineNumberTableAttribute(
      LineNumberTableAttribute line_number_table_attribute_);
  void setInnerClassesAttribute(InnerClassesAttribute inner_classes_attribute_);
  void setExceptionsAttribute(ExceptionsAttribute exceptions_attribute_);
  void setBootstrapMethod(BootstrapMethod bootstrap_method_);
  void setUnparsedAttribute(UnparsedAttribute unparsed_attribute_);
  void
  setConstantValueAttribute(ConstantValueAttribute constant_value_attribute_);
  void setEnclosingMethodAttribute(
      EnclosingMethodAttribute enclosing_method_attribute_);
  CodeAttribute getCodeAttribute();
  SourceFileAttribute getSourceFileAttribute();
  SignatureAttribute getSignatureAttribute();
  DeprecatedAttribute getDeprecatedAttribute();
  SyntheticAttribute getSyntheticAttribute();
  LocalVariableTypeTableAttribute getLocalVariableTypeTableAttribute();
  LocalVariableTableAttribute getLocalVariableTableAttribute();
  LineNumberTableAttribute getLineNumberTableAttribute();
  InnerClassesAttribute getInnerClassesAttribute();
  ExceptionsAttribute getExceptionsAttribute();
  BootstrapMethod getBootstrapMethod();
  UnparsedAttribute getUnparsedAttribute();
  ConstantValueAttribute getConstantValueAttribute();
  EnclosingMethodAttribute getEnclosingMethodAttribute();
};

#endif // ATTRIBUTEINFO_H
