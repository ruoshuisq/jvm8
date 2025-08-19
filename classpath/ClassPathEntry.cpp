//
// Created by zj on 2025/7/16.
//

#include "ClassPathEntry.h"
#include <io.h>
#include <iostream>
#include <vector>
#include <stdio.h>

#include "unzip.h"

ClassPathEntry::ClassPathEntry(std::string jreOption,std::string cpOption) {
    ClassPathEntry::jreOption=jreOption;
    ClassPathEntry::cpOption=cpOption;
}

Entry ClassPathEntry::readClass(std::string className) {
    const std::string classNameConst=className+".class";
    //先在bootClasspath下查找，即jre/lib/下的jar包
    std::vector<std::string> libFiles;
    getFiles(jreOption+"/lib",libFiles);
    for (std::string zipName : libFiles) {
        ClassPathZipEntry class_path_zip_entry = ClassPathZipEntry(zipName);
        Entry read_class = class_path_zip_entry.readClass(classNameConst);
        if(read_class.data!=nullptr) {
            return read_class;
        }
    }

    //再在extClasspath下查找，即jre/lib/ext/下的jar包
    std::vector<std::string> extFiles;
    std::string ext=jreOption;
    getFiles(ext.append("/lib/ext"),extFiles);
    for (std::string zipName : libFiles) {
        ClassPathZipEntry class_path_zip_entry = ClassPathZipEntry(zipName);
        Entry read_class = class_path_zip_entry.readClass(classNameConst);
        if(read_class.data!=nullptr) {
            return read_class;
        }
    }

    //最后在userClasspath下查找，即用户下的jar包或者目录
    //1.直接用cp+className读取
    ClassPathDirEntry class_path_dir_entry = ClassPathDirEntry(cpOption.data());
    Entry class_ = class_path_dir_entry.readClass(classNameConst);
    if(class_.data!=nullptr) {
        return class_;
    }
    //2.如果有jar包，在jar包下找
    std::vector<std::string> cpFiles;
    getFiles(cpOption,cpFiles);
    for (std::string zipName : cpFiles) {
        ClassPathZipEntry class_path_zip_entry = ClassPathZipEntry(zipName);
        Entry read_class = class_path_zip_entry.readClass(classNameConst);
        if(read_class.data!=nullptr) {
            return read_class;
        }
    }

    Entry entry;
    entry.data=nullptr;
    entry.error="Could not find class "+classNameConst;
    return entry;
}


 ClassPathDirEntry::ClassPathDirEntry(std::string absDir){
    ClassPathDirEntry::absDir=absDir;
}
Entry ClassPathDirEntry::readClass(std::string className) {
    FILE *fp;
    //c++ 流的操作,mode必须是rb，为二进制文件读取，如果用r有bug,0x1a会被误识别为0xff，从而提取终止文件读取
    errno_t err;
    err=fopen_s(&fp,absDir.append(pathSeparator).append(className).c_str(), "rb");
    Entry entry;
    entry.data=nullptr;
    if (err == 0) {
        //获取文件长度
        fseek(fp, 0, SEEK_END);
        const unsigned int len_file = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        char *data = new char[len_file];  // ftell(fp)函数可获取此文件字节个数 ， 然后申请count个字节的内存空间
        int i,c;
        int cur = 0;
        //下面将流中的字节复制到自己申请的内存中
        for( i=0; (i < len_file ) && ( feof( fp ) == 0 ); i++ ) {
            c = fgetc(fp);
            // printf("%x ",c);
            *(data + cur) = c;
            cur++;
        }
        fclose(fp);
        entry.data=data;
    }else {
        entry.error="file not found!";
        printf("无法打开文件，错误代码: %d\n", err);
    }
    return entry;
}

ClassPathZipEntry::ClassPathZipEntry(std::string zipName){
    ClassPathZipEntry::zipName=zipName;
}

Entry ClassPathZipEntry::readClass(std::string className) {
    Entry entry;
    entry.data=nullptr;
    unzFile uf = unzOpen(zipName.data());
    if(uf == NULL)
    {
        entry.error="Error opening "+ zipName;
        return entry;
    }

    // 打开文件
    int err = unzLocateFile(uf, className.data(), 0);
    if(err != UNZ_OK)
    {
        entry.error="Error locating " + className + " in " + zipName;
        unzClose(uf);
        return entry;
    }

    unz_file_info file_info;
    char filename[512];
    err = unzGetCurrentFileInfo(uf, &file_info, filename, sizeof(filename), NULL, 0, NULL, 0);
    if(err != UNZ_OK)
    {
        entry.error= "Error getting file info for " + className;
        unzClose(uf);
        return entry;
    }

    // 打开文件
    err = unzOpenCurrentFile(uf);
    if(err != UNZ_OK)
    {
        entry.error= "Error opening " + className;
        unzClose(uf);
        return entry;
    }

    // // 读取文件
    // char *buf = new char[file_info.uncompressed_size];
    // // std::vector<char> buf(file_info.uncompressed_size);
    // int len = unzReadCurrentFile(uf, &buf[0], sizeof(buf));
    //读取内容
    int size = file_info.uncompressed_size;
    char * buf;
    buf = (char*)malloc(size); //动态分配内存

    int len = unzReadCurrentFile(uf, buf, size);
    if(len < 0)
    {
        entry.error= "Error reading " + className;
        unzCloseCurrentFile(uf);
        unzClose(uf);
        return entry;
    }

    // 关闭文件
    unzCloseCurrentFile(uf);
    unzClose(uf);

    // 输出文件

    entry.data=buf;
    // printf(buf);
    printf("\n");
    return entry;
    // std::cout << "Content of " << file << ":" << std::endl;
    // std::cout.write(&buf[0], len);
    // std::cout << std::endl;
}
