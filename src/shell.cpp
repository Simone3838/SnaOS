#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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