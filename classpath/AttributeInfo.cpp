//
// Created by zj on 2025/7/19.
//

#include "AttributeInfo.h"
#include <cstdint>

CodeAttribute AttributeInfo::getCodeAttribute() {
  return code_attribute_;
}
SourceFileAttribute AttributeInfo::getSourceFileAttribute() {
  return source_file_attribute_;
}
SignatureAttribute AttributeInfo::getSignatureAttribute() {
  return signature_attribute_;
}
DeprecatedAttribute AttributeInfo::getDeprecatedAttribute() {
  return deprecated_attribute_;
}
SyntheticAttribute AttributeInfo::getSyntheticAttribute() {
  return synthetic_attribute_;
}
LocalVariableTypeTableAttribute
AttributeInfo::getLocalVariableTypeTableAttribute() {
  return local_variable_type_table_attribute_;
}
LocalVariableTableAttribute AttributeInfo::getLocalVariableTableAttribute() {
  return local_variable_table_attribute_;
}
LineNumberTableAttribute AttributeInfo::getLineNumberTableAttribute() {
  return line_number_table_attribute_;
}
InnerClassesAttribute AttributeInfo::getInnerClassesAttribute() {
  return inner_classes_attribute_;
}
ExceptionsAttribute AttributeInfo::getExceptionsAttribute() {
  return exceptions_attribute_;
}
BootstrapMethod AttributeInfo::getBootstrapMethod() {
  return bootstrap_method_;
}
UnparsedAttribute AttributeInfo::getUnparsedAttribute() {
  return unparsed_attribute_;
}
ConstantValueAttribute AttributeInfo::getConstantValueAttribute() {
  return constant_value_attribute_;
}
EnclosingMethodAttribute AttributeInfo::getEnclosingMethodAttribute() {
  return enclosing_method_attribute_;
}

void AttributeInfo::setCodeAttribute(CodeAttribute code_attribute_) {
  AttributeInfo::code_attribute_ = code_attribute_;
}
void AttributeInfo::setSourceFileAttribute(
    SourceFileAttribute source_file_attribute_) {
  AttributeInfo::source_file_attribute_ = source_file_attribute_;
}
void AttributeInfo::setSignatureAttribute(
    SignatureAttribute signature_attribute_) {
  AttributeInfo::signature_attribute_ = signature_attribute_;
}
void AttributeInfo::setDeprecatedAttribute(
    DeprecatedAttribute deprecated_attribute_) {
  AttributeInfo::deprecated_attribute_ = deprecated_attribute_;
}
void AttributeInfo::setSyntheticAttribute(
    SyntheticAttribute synthetic_attribute_) {
  AttributeInfo::synthetic_attribute_ = synthetic_attribute_;
}
void AttributeInfo::setLocalVariableTypeTableAttribute(
    LocalVariableTypeTableAttribute local_variable_type_table_attribute_) {
  AttributeInfo::local_variable_type_table_attribute_ =
      local_variable_type_table_attribute_;
}
void AttributeInfo::setLocalVariableTableAttribute(
    LocalVariableTableAttribute local_variable_table_attribute_) {
  AttributeInfo::local_variable_table_attribute_ =
      local_variable_table_attribute_;
}
void AttributeInfo::setLineNumberTableAttribute(
    LineNumberTableAttribute line_number_table_attribute_) {
  AttributeInfo::line_number_table_attribute_ = line_number_table_attribute_;
}
void AttributeInfo::setInnerClassesAttribute(
    InnerClassesAttribute inner_classes_attribute_) {
  AttributeInfo::inner_classes_attribute_ = inner_classes_attribute_;
}
void AttributeInfo::setExceptionsAttribute(
    ExceptionsAttribute exceptions_attribute_) {
  AttributeInfo::exceptions_attribute_ = exceptions_attribute_;
}
void AttributeInfo::setBootstrapMethod(BootstrapMethod bootstrap_method_) {
  AttributeInfo::bootstrap_method_ = bootstrap_method_;
}
void AttributeInfo::setUnparsedAttribute(
    UnparsedAttribute unparsed_attribute_) {
  AttributeInfo::unparsed_attribute_ = unparsed_attribute_;
}
void AttributeInfo::setConstantValueAttribute(
    ConstantValueAttribute constant_value_attribute_) {
  AttributeInfo::constant_value_attribute_ = constant_value_attribute_;
}
void AttributeInfo::setEnclosingMethodAttribute(
    EnclosingMethodAttribute enclosing_method_attribute_) {
  AttributeInfo::enclosing_method_attribute_ = enclosing_method_attribute_;
}


void AttributeInfo::readAttributeInfo(ClassReader &reader,
                                          ConstantPool &constant_pool) {
  u2 attrNameIndex = reader.readU2();
  std::string attrName = constant_pool.getStringFromPool(attrNameIndex);
  u4 attrLen = reader.readU4();
  switch (hash_compile_time(attrName.data())) {
  case "BootstrapMethods"_hash: {
    u2 numBootstrapMethods = reader.readU2();
    for (int i = 0; i < numBootstrapMethods; i++) {
      u2 bootstrapMethodRef = reader.readU2();
      u2 *bootstrapArguments = reader.readU2s();
      bootstrap_method_.bootstrapMethodRef=bootstrapMethodRef;
      bootstrap_method_.bootstrapArguments=bootstrapArguments;
    }
    break;
  }
  case "Code"_hash: {
    u2 maxStack = reader.readU2();
    u2 maxLocals = reader.readU2();
    u4 codeLength = reader.readU4();
    char *code = new char[codeLength];
    reader.readUn(codeLength, code);
    code_attribute_.maxStack=maxStack;
    code_attribute_.maxLocals=maxLocals;
    code_attribute_.code=code;
    code_attribute_.constantPool=&constant_pool;
    u2 exceptionTableLength = reader.readU2();
    code_attribute_.exceptionTable=new ExceptionTableEntry[exceptionTableLength];
    for (int i = 0; i < exceptionTableLength; i++) {
      u2 startPc = reader.readU2();
      u2 endPc = reader.readU2();
      u2 handlerPc = reader.readU2();
      u2 catchType = reader.readU2();
      ExceptionTableEntry exception_table_entry;
      code_attribute_.exceptionTable[i].startPc=startPc;
      code_attribute_.exceptionTable[i].endPc=endPc;
      code_attribute_.exceptionTable[i].handlerPc=handlerPc;
      code_attribute_.exceptionTable[i].catchType=catchType;
      // readAttributeInfo(reader, constant_pool); // TODO
    }
    // 读取code中的属性
    u2 codeAttLength = reader.readU2();
    for (int i = 0; i < codeAttLength; i++) {
      readAttributeInfo(reader, constant_pool);
    }
    printf("操作数栈深度：%d，局部变量表大小：%d\n",maxStack,maxLocals);

    break;
  }

  case "ConstantValue"_hash: {
    u2 constantValueIndex = reader.readU2();
    constant_value_attribute_.constantValueIndex=constantValueIndex;
    break;
  }

  case "Deprecated"_hash: {
    // read nothing
    break;
  }

  case "EnclosingMethod"_hash: {
    u2 classIndex = reader.readU2();
    u2 methodIndex = reader.readU2();
    enclosing_method_attribute_.classIndex=classIndex;
    enclosing_method_attribute_.methodIndex=methodIndex;
    enclosing_method_attribute_.constantPool=&constant_pool;
    break;
  }

  case "Exceptions"_hash: {
    u2 *exceptionIndexTable = reader.readU2s();
    exceptions_attribute_.exceptionIndexTable=exceptionIndexTable;
    break;
  }

  case "InnerClasses"_hash: {
    u2 numberOfClasses = reader.readU2();
    inner_classes_attribute_.classes=new InnerClassInfo[numberOfClasses];
    for (int i = 0; i < numberOfClasses; i++) {
      u2 innerClassInfoIndex = reader.readU2();
      u2 outerClassInfoIndex = reader.readU2();
      u2 innerNameIndex = reader.readU2();
      u2 innerClassAccessFlags = reader.readU2();
      inner_classes_attribute_.classes[i].innerClassInfoIndex=innerClassInfoIndex;
      inner_classes_attribute_.classes[i].outerClassInfoIndex=outerClassInfoIndex;
      inner_classes_attribute_.classes[i].innerNameIndex=innerNameIndex;
      inner_classes_attribute_.classes[i].innerClassAccessFlags=innerClassAccessFlags;
    }
    break;
  }

  case "LineNumberTable"_hash: {
    u2 lineNumberTableLength = reader.readU2();
    LineNumberTableAttribute line_number_table_attribute;
    code_attribute_.lineNumberTableAttribute=&line_number_table_attribute;
    code_attribute_.lineNumberTableAttribute->lineNumberTable=new LineNumberTableEntry[lineNumberTableLength];
    for (int i = 0; i < lineNumberTableLength; i++) {
      u2 startPc = reader.readU2();
      u2 lineNumber = reader.readU2();
      code_attribute_.lineNumberTableAttribute->lineNumberTable[i].startPc=startPc;
      code_attribute_.lineNumberTableAttribute->lineNumberTable[i].lineNumber=lineNumber;
    }
    break;
  }

  case "LocalVariableTable"_hash: {
    u2 localVariableTableLength = reader.readU2();
    LocalVariableTableAttribute local_variable_table_attribute;
    code_attribute_.localVariableTableAttribute=&local_variable_table_attribute;
    code_attribute_.localVariableTableAttribute->localVariableTable=new LocalVariableTableEntry[localVariableTableLength];
    for (int i = 0; i < localVariableTableLength; i++) {
      u2 startPc = reader.readU2();
      u2 length = reader.readU2();
      u2 nameIndex = reader.readU2();
      u2 descriptorIndex = reader.readU2();
      u2 index = reader.readU2();
      code_attribute_.localVariableTableAttribute->localVariableTable[i].startPc=startPc;
      code_attribute_.localVariableTableAttribute->localVariableTable[i].length=length;
      code_attribute_.localVariableTableAttribute->localVariableTable[i].nameIndex=nameIndex;
      code_attribute_.localVariableTableAttribute->localVariableTable[i].descriptorIndex=descriptorIndex;
      code_attribute_.localVariableTableAttribute->localVariableTable[i].index=index;
    }
    break;
  }
  case "LocalVariableTypeTable"_hash: {
    u2 localVariableTypeTableLength = reader.readU2();
    LocalVariableTypeTableAttribute local_variable_type_table_attribute;
    code_attribute_.localVariableTypeTableAttribute=&local_variable_type_table_attribute;
    code_attribute_.localVariableTypeTableAttribute->localVariableTypeTable=new LocalVariableTypeTableEntry[localVariableTypeTableLength];
    for (int i = 0; i < localVariableTypeTableLength; i++) {
      u2 startPc = reader.readU2();
      u2 length = reader.readU2();
      u2 nameIndex = reader.readU2();
      u2 signatureIndex = reader.readU2();
      u2 index = reader.readU2();
      code_attribute_.localVariableTypeTableAttribute->localVariableTypeTable[i].startPc=startPc;
      code_attribute_.localVariableTypeTableAttribute->localVariableTypeTable[i].length=length;
      code_attribute_.localVariableTypeTableAttribute->localVariableTypeTable[i].nameIndex=nameIndex;
      code_attribute_.localVariableTypeTableAttribute->localVariableTypeTable[i].signatureIndex=signatureIndex;
      code_attribute_.localVariableTypeTableAttribute->localVariableTypeTable[i].index=index;
    }
    break;
  }
  case "Signature"_hash: {
    u2 signatureIndex = reader.readU2();
    signature_attribute_.signatureIndex=signatureIndex;
    signature_attribute_.constantPool=&constant_pool;
    break;
  }
  case "SourceFile"_hash: {
    u2 sourceFileIndex = reader.readU2();
    source_file_attribute_.sourceFileIndex=sourceFileIndex;
    source_file_attribute_.constantPool=&constant_pool;
    break;
  }
  default: {
    char *target = new char[attrLen];
    reader.readUn(attrLen, target);
    break;
  }
  }
}

