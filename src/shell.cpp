#include "filesystem.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Function declarations
void clock();
void bouncing_ball();
void start_gui();
void start_cursor();
void start_cursor_sprite();
void start_minesweeper();
void start_sheepsay();

// Global file system instance
FileSystem fs;

// Function to split input into tokens
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to handle built-in shell commands
void execute_command(const std::vector<std::string>& args) {
    if (args.empty()) return;

    if (args[0] == "echo") {
        for (size_t i = 1; i < args.size(); ++i) {
            std::cout << args[i] << " ";
        }
        std::cout << std::endl;
    } else if (args[0] == "exit") {
        std::cout << "Exiting shell..." << std::endl;
        exit(0);
    } else if (args[0] == "clock") {
        clock();
    } else if (args[0] == "bouncingball") {
        bouncing_ball();
    } else if (args[0] == "gui") {
        start_gui();
    } else if (args[0] == "cursor") {
        start_cursor();
    } else if (args[0] == "cursorsprite") {
        start_cursor_sprite();
    } else if (args[0] == "minesweeper") {
        start_minesweeper();
    } else if (args[0] == "sheepsay") {
        start_sheepsay();
    } else if (args[0] == "create") {
        if (args.size() < 3) {
            std::cout << "Usage: create <path> <name> <dir/file>" << std::endl;
            return;
        }
        bool isDirectory = (args[3] == "dir");
        if (fs.createFile(args[1], args[2], isDirectory)) {
            std::cout << "Created " << (isDirectory ? "directory" : "file") << ": " << args[2] << std::endl;
        } else {
            std::cout << "Failed to create " << args[2] << std::endl;
        }
    } else if (args[0] == "write") {
        if (args.size() < 4) {
            std::cout << "Usage: write <path> <name> <content>" << std::endl;
            return;
        }
        File* file = fs.findFile(args[1] + "/" + args[2]);
        if (file) {
            fs.writeFile(file, args[3]);
            std::cout << "Written to file: " << args[2] << std::endl;
        } else {
            std::cout << "File not found: " << args[2] << std::endl;
        }
    } else if (args[0] == "read") {
        if (args.size() < 3) {
            std::cout << "Usage: read <path> <name>" << std::endl;
            return;
        }
        File* file = fs.findFile(args[1] + "/" + args[2]);
        if (file) {
            std::cout << "Content of " << args[2] << ": " << fs.readFile(file) << std::endl;
        } else {
            std::cout << "File not found: " << args[2] << std::endl;
        }
    } else if (args[0] == "delete") {
        if (args.size() < 3) {
            std::cout << "Usage: delete <path> <name>" << std::endl;
            return;
        }
        fs.deleteFile(args[1], args[2]);
        std::cout << "Deleted: " << args[2] << std::endl;
    } else if (args[0] == "readme") {
        File* file = fs.findFile("/Readme.txt");
        if (file) {
            std::cout << "Content of Readme.txt: " << fs.readFile(file) << std::endl;
        } else {
            std::cout << "Readme.txt not found." << std::endl;
        }
    } else {
        std::cout << "Unknown command: " << args[0] << std::endl;
    }
}

// Simple shell function
extern "C" void shell() {
    std::string input;
    while (true) {
        std::cout << "SnaOS> ";
        std::getline(std::cin, input);

        std::vector<std::string> args = split(input, ' ');
        execute_command(args);
    }
}
