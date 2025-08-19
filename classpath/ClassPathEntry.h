//
// Created by zj on 2025/7/16.
//

#ifndef CLASSPATHENTRY_H
#define CLASSPATHENTRY_H
#include <string>
#include <io.h>
#include <iostream>
#include <vector>
struct Entry {
    char *data;
    std::string error;
};

static const  std::string pathSeparator="\\";
static const  std::string pathListSeparator=";";
static const bool endsWith(const std::string& str, const std::string& suffix) {
    if (str.length() < suffix.length()) {
        return false;
    }
    return std::tolower(equal(suffix.rbegin(), suffix.rend(), str.rbegin()));
}

/**
 * 获取目录下jar包，不包含子目录
 * @param path
 * @param files
 */
static const void getFiles(const std::string& path, std::vector<std::string>& files) {
    _finddata_t file_info;
    std::string current_path = path + "/*.*";
    intptr_t handle = _findfirst(current_path.c_str(), &file_info);
    if (handle == -1) return;

    do {
        if(endsWith(file_info.name,".jar")) {
            files.push_back(path + "/" + file_info.name);
        }
    } while (_findnext(handle, &file_info) == 0);

    _findclose(handle);
}

static const void getDirs(const std::string& path, std::vector<std::string>& files) {
    _finddata_t file_info;
    std::string current_path = path + "/*.*";
    intptr_t handle = _findfirst(current_path.c_str(), &file_info);
    if (handle == -1) return;

    do {
        if(file_info.attrib & _A_SUBDIR) {
            files.push_back(path + "/" + file_info.name);
        }
    } while (_findnext(handle, &file_info) == 0);

    _findclose(handle);
}

class ClassPathEntry {

private:
    std::string jreOption;
    std::string cpOption;

public:
    //构造方法
    ClassPathEntry(std::string jreOption,std::string cpOption);
    Entry readClass(std::string className ) ;
    std::string String() ;

};

class ClassPathDirEntry  {
private:
    std::string absDir;
public:
    ClassPathDirEntry(std::string absDir);
    Entry readClass(std::string className ) ;
    std::string String() ;
};

class ClassPathZipEntry  {
private:
    Entry enrty;
    std::string zipName;
public:
    ClassPathZipEntry(std::string zipName);
    Entry readClass(std::string className ) ;
    std::string String();
};

#endif //CLASSPATHENTRY_H
