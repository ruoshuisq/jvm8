//
// Created by zj on 2025/7/19.
//

#ifndef BASICTYPE_H
#define BASICTYPE_H

#define MAGIC 0xCAFEBABE
// 常量池枚举
#define CONSTANT_Class 7
#define CONSTANT_Fieldref 9
#define CONSTANT_Methodref 10
#define CONSTANT_InterfaceMethodref 11
#define CONSTANT_String 8
#define CONSTANT_Integer 3
#define CONSTANT_Float 4
#define CONSTANT_Long 5
#define CONSTANT_Double 6
#define CONSTANT_NameAndType 12
#define CONSTANT_Utf8 1
#define CONSTANT_MethodHandle 15
#define CONSTANT_MethodType 16
#define CONSTANT_InvokeDynamic 18

typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef long unsigned u8;
typedef  char s1;
typedef  short s2;
typedef  int s4;
typedef long s8;

#include <cstdint>

enum attr_name {
  AnnotationDefault,
  BootstrapMethods,
  Code,
  ConstantValue,
  Deprecated,
  EnclosingMethod,
  Exceptions,
  InnerClasses,
  LineNumberTable,
  LocalVariableTable,
  LocalVariableTypeTable,
  MethodParameters,
  RuntimeInvisibleAnnotations,
  RuntimeInvisibleParameterAnnotations,
  RuntimeInvisibleTypeAnnotations,
  RuntimeVisibleAnnotations,
  RuntimeVisibleParameterAnnotations,
  RuntimeVisibleTypeAnnotations,
  Signature,
  SourceFile,
  SourceDebugExtension,
  StackMapTable,
  Synthetic
};

#define  ACC_PUBLIC        0x0001 // class field method
#define  ACC_PRIVATE       0x0002 //       field method
#define  ACC_PROTECTED     0x0004 //       field method
#define  ACC_STATIC        0x0008 //       field method
#define  ACC_FINAL         0x0010 // class field method
#define  ACC_SUPER         0x0020 // class
#define  ACC_SYNCHRONIZED  0x0020 //             method
#define  ACC_VOLATILE      0x0040 //       field
#define  ACC_BRIDGE        0x0040 //             method
#define  ACC_TRANSIENT     0x0080 //       field
#define  ACC_VARARGS       0x0080 //             method
#define  ACC_NATIVE        0x0100 //             method
#define  ACC_INTERFACE     0x0200 // class
#define  ACC_ABSTRACT      0x0400 // class       method
#define  ACC_STRICT        0x0800 //             method
#define  ACC_SYNTHETIC     0x1000 // class field method
#define  ACC_ANNOTATION    0x2000 // class
#define  ACC_ENUM          0x4000 // class field

typedef std::uint64_t hash_t;
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

constexpr hash_t hash_compile_time(const char *str, hash_t last_value = basis) {
  return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime)
              : last_value;
}

constexpr unsigned long long operator"" _hash(const char *p, size_t) {
    return hash_compile_time(p);
}

class BasicType {};

#endif // BASICTYPE_H
