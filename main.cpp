

#include "classpath/ClassReader.h"
#include "cmd.h"
#include <winsock2.h>

#include "classpath/ClassPathEntry.h"

// #pragma comment(lib, "zlib/zlibwapi.lib")
// #pragma comment(lib, "zlib/miniunz.lib")
// #pragma comment(lib, "zlib/minizip.lib")
#include "classpath/ClassFile.h"
#include "rtda/Frame.h"
#include "rtda/Stack.h"
#include "rtda/Thread.h"
#include "test/ClassPathEntryTest.h"
#include "unzip.h"

#include "../rtda/interpret.h"
#include <signal.h>
#include <unistd.h>

#include "rtda/heap/ClassLoader.hpp"
#include "rtda/heap/JClass.hpp"

#define STRING_BUFFER 16
char strbuf[STRING_BUFFER] = {0};
// extern "C"
// {
// #include <zlib.h>
// }
void handle_sigsegv(int sig);
void startJVM(Cmd cmd);
void loadClass(std::string className, ClassPathEntry class_path_entry,
               ClassFile &class_file);
int main() {
  system("chcp 65001>nul");

  // 注册 SIGSEGV 信号处理函数
  signal(SIGSEGV, handle_sigsegv);
  setvbuf(stdout, NULL, _IONBF, 0); // 禁用缓冲区
  Cmd cmd;
  parseCmd(cmd);
  printUsage();

  cmd.XjreOption = "C:/work/java/jdk/jdk1.8.0_131/jre";
  // std::string cp="C:/work/workspace2/myjvm/src/main/java";
  cmd.cpOption = "C:/work/ws-jvm/test-myjvm/target/classes";
  cmd.mainClass = "test/ch06/MyObject";
  cmd.args = {"1", "2"};
  startJVM(cmd);
  return 0;
}
void startJVM(Cmd cmd) {
    ClassPathEntry class_path_entry =
        ClassPathEntry(cmd.XjreOption, cmd.cpOption);
    ClassLoader * class_loader=new ClassLoader(class_path_entry);
    JClass * main_class = class_loader->loadClass(cmd.mainClass);
    Method * main_method = main_class->getMainMethod();
    if(main_method!=nullptr) {
        run(*main_method, cmd.args);
    }else {
        printf("Main method not found in class %s\n", cmd.mainClass.data());
    }
}

// void startJVM(Cmd cmd) {
//   ClassPathEntry class_path_entry =
//       ClassPathEntry(cmd.XjreOption, cmd.cpOption);
//   ClassFile *class_file = new ClassFile();
//   loadClass(cmd.klass, class_path_entry, *class_file);
//   for (auto &pair : *class_file->methods) {
//     MemberInfo memberInfo = pair.second;
//     std::string name = memberInfo.Name();
//     if (strcmp("main", pair.second.Name().data()) == 0 &&
//         strcmp("([Ljava/lang/String;)V", pair.second.Descriptor().data()) ==
//             0) {
//       run(pair.second, cmd.args);
//     }
//   }
// }
//
// void loadClass(std::string className, ClassPathEntry class_path_entry,
//                ClassFile &class_file) {
//   Entry read_class = class_path_entry.readClass(className);
//   ClassReader class_reader = ClassReader(read_class.data);
//   class_file.parse(class_reader);
// }

// 自定义信号处理函数
void handle_sigsegv(int sig) {
  printf("捕获到信号 %d (SIGSEGV): 段错误！\n", sig);
  exit(1); // 退出程序以避免进一步的崩溃
}
