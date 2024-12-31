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
