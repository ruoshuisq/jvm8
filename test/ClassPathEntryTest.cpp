////
//// Created by zj on 2025/7/18.
////
//
//#include "ClassPathEntryTest.h"
//#include "../classpath/ClassPathEntry.h"
//
//#include "../rtda/Frame.h"
//#include <string>
//#include <winsock2.h>
//
//static void test1() {
//    std::string path="C:\\work\\workspace2\\myjvm\\src\\main\\java\\test\\ch05";
//    // ClassRead *classRead = ClassRead::readByPath(path);
//    // printf("%X\n", classRead->readByFourByte());
//    // printf(dir);
//
//    ClassPathDirEntry class_path_dir_entry=ClassPathDirEntry(path);
//    Entry read_class = class_path_dir_entry.readClass("Constants.class");
//    if(read_class.error.empty()) {
//        int cur=0;
//        int *res = (int *) (read_class.data+cur);
//        cur = cur + 4;
//        u_long long_ = htonl(*res);
//        printf("%X\n", long_);
//    }
//
//    // Zip 文件名
//    std::string zipfile = "C:/work/java/jdk/jdk1.8.0_131/lib/tools.jar";
//    // 需要读取的文件
//    ClassPathZipEntry class_path_zip_entry = ClassPathZipEntry(zipfile);
//    Entry entry = class_path_zip_entry.readClass("sun/tools/util/CommandLine.class");
//    if(entry.error.empty()) {
//        int cur=0;
//        int *res = (int *) (entry.data+cur);
//        cur = cur + 4;
//        u_long long_ = htonl(*res);
//        printf("%X\n", long_);
//    }
//
//}
//
//static void test2() {
//    std::vector<std::string> libFiles;
//    getFiles("C:/work/java/jdk/jdk1.8.0_131/jre/lib",libFiles);
//    for (std::string lib_file : libFiles) {
//        printf(lib_file.data());
//        printf("\n");
//    }
//}
//
//static void test3() {
//    std::string jre="C:/work/java/jdk/jdk1.8.0_131/jre";
//    std::string cp="C:/work/maven/repository/com/stephen/mall/common/mall-common/0.0.1-SNAPSHOT";
//    ClassPathEntry class_path_entry = ClassPathEntry(jre,cp);
//    Entry read_class = class_path_entry.readClass("com/stephen/mall/common/constant/CartConstant");
//    if(read_class.data!=nullptr) {
//        if(read_class.error.empty()) {
//            int cur=0;
//            int *res = (int *) (read_class.data+cur);
//            cur = cur + 4;
//            u_long long_ = htonl(*res);
//            printf("%X\n", long_);
//        }
//    }else {
//        printf(read_class.error.data());
//    }
//}
//
//void testThread() {
//    Thread *thread=new Thread();
//    Frame frame1=thread->newFrame(10,10);
//    thread->pushFrame(frame1);
//    Frame frame2=thread->newFrame(20,20);
//    thread->pushFrame(frame2);
//    Frame *frame3=thread->popFrame();
//    Frame *frame4=thread->popFrame();
//    printf("1---%d\n",frame1.hash);
//    printf("2---%d\n",frame2.hash);
//    printf("2---%d\n",frame3->hash);
//    printf("1---%d\n",frame4->hash);
//}
//
//void testLocalVars() {
//
//    Frame frame = Stack::initFrame(10,10);
//    frame.localVars_->setInt(0,10);
//    frame.localVars_->setLong(1,10000l);
//    frame.localVars_->setFloat(2,10.1f);
//    frame.localVars_->setDouble(3,10.100001);
//    Object *object=new Object();
//    frame.localVars_->setRef(4,*object);
//    // int int_ = frame.localVars_->getInt(0);
//    // long long_ = frame.localVars_->getLong(1);
//    // float float_ = frame.localVars_->getFloat(2);
//    // double double_ = frame.localVars_->getDouble(3);
//    // Object * ref = frame.localVars_->getRef(4);
//
//    // printf("%p\n",ref);
//    // printf("%d\n",int_);
//    // printf("%ld\n",long_);
//    // printf("%f\n",float_);
//    // printf("%f\n",double_);
//    Frame frame2 = Stack::initFrame(20,20);
//    printf("1---%d\n",frame.hash);
//    printf("2---%d\n",frame2.hash);
//    Stack *stack=new Stack(1024);
//    // printf("------%d\n",stack->isEmpty());
//    stack->push(frame);
//    stack->push(frame2);
//    Frame *frames=stack->getFrames();
//    for(int i=0;i<2;i++) {
//        Frame tmp=frames[i];
//        printf("----%d\n",tmp.hash);
//    }
//    // printf("------%d\n",stack->isEmpty());
//    // Frame *frame3=stack->top();
//    // Frame *frame4=stack->pop();
//    // Frame *frame5=stack->top();
//    // Frame *frame6=stack->pop();
//    // printf("%p\n",&frame2);
//    // printf("%p\n",frame3);
//    // printf("%p\n",frame4);
//    // printf("--%p\n",&frame);
//    // printf("--%p\n",frame5);
//    // printf("--%p\n",frame6);
//    // printf("------%d\n",stack->isEmpty());
//
//}
//
//void testOperandStack() {
//
//    Frame frame = Stack::initFrame(10,10);
//    // Stack *stack=new Stack(1024,1,frame);
//    // stack->push(frame);
//    Object *object=new Object();
//    printf("%p\n",object);
//    frame.operandStack_->pushInt(1);
//    frame.operandStack_->pushLong(10000l);
//    frame.operandStack_->pushFloat(10.1f);
//    frame.operandStack_->pushDouble(123.100001);
//    frame.operandStack_->pushObject(*object);
//    Object *object2=frame.operandStack_->popObject();
//    double double_ = frame.operandStack_->popDouble();
//    float float_ = frame.operandStack_->popFloat();
//    long long_ = frame.operandStack_->popLong();
//    int int_ = frame.operandStack_->popInt();
//
//    printf("%p\n",object2);
//    printf("%d\n",int_);
//    printf("%ld\n",long_);
//    printf("%f\n",float_);
//    printf("%f\n",double_);
//}