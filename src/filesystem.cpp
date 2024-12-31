// filesystem.cpp
#include "filesystem.h"
#include <sstream>
#include <algorithm>

FileSystem::FileSystem() {
    root = new File("root", true);

    // Create the Readme.txt file in the root directory with the welcome message
    File* readme = createFile("/", "Readme.txt", false);
    if (readme) {
        writeFile(readme, "Welcome to SnaOS!");
    }
}

File* FileSystem::createFile(const std::string& path, const std::string& name, bool isDirectory) {
    File* dir = traversePath(path);
    if (dir && dir->isDirectory) {
        File* newFile = new File(name, isDirectory);
        dir->children.push_back(newFile);
        return newFile;
    }
    return nullptr;
}

File* FileSystem::findFile(const std::string& path) {
    return traversePath(path);
}

void FileSystem::writeFile(File* file, const std::string& content) {
    if (file && !file->isDirectory) {
        file->content = content;
    }
}

std::string FileSystem::readFile(File* file) {
    if (file && !file->isDirectory) {
        return file->content;
    }
    return "";
}

void FileSystem::deleteFile(const std::string& path, const std::string& name) {
    File* dir = traversePath(path);
    if (dir && dir->isDirectory) {
        auto it = std::remove_if(dir->children.begin(), dir->children.end(),
                                 [&name](File* file) { return file->name == name; });
        if (it != dir->children.end()) {
            delete *it;
            dir->children.erase(it, dir->children.end());
        }
    }
}

File* FileSystem::traversePath(const std::string& path) {
    std::istringstream ss(path);
    std::string token;
    File* current = root;
    while (std::getline(ss, token, '/')) {
        if (token.empty()) continue;
        bool found = false;
        for (auto& child : current->children) {
            if (child->name == token && child->isDirectory) {
                current = child;
                found = true;
                break;
            }
        }
        if (!found) return nullptr;
    }
    return current;
}
