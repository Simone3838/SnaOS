// filesystem.h
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <vector>

struct File {
    std::string name;
    std::string content;
    bool isDirectory;
    std::vector<File*> children;

    File(std::string name, bool isDirectory)
        : name(name), isDirectory(isDirectory) {}
};

class FileSystem {
public:
    FileSystem();
    File* createFile(const std::string& path, const std::string& name, bool isDirectory);
    File* findFile(const std::string& path);
    void writeFile(File* file, const std::string& content);
    std::string readFile(File* file);
    void deleteFile(const std::string& path, const std::string& name);

private:
    File* root;
    File* traversePath(const std::string& path);
};

#endif // FILESYSTEM_H
