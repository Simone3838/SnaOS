#include <iostream>
#include <string>

// Function declarations
void shell();  // Assuming shell() is defined elsewhere

// Function to clear the screen (platform dependent)
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

// Function to display a welcome screen
void displayWelcomeScreen() {
    clearScreen();
    std::cout << "====================================" << std::endl;
    std::cout << "          Welcome to SnaOS          " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Type 'help' to see available commands" << std::endl;
    std::cout << "====================================" << std::endl;
}

// Simple login function
void login() {
    std::string username;
    std::string password;
    bool success = false;

    while (!success) {
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        // Simple authentication check
        if (username == "admin" && password == "password") {
            success = true;
        } else {
            std::cout << "Invalid credentials, please try again." << std::endl;
        }
    }

    // Display welcome screen after successful login
    displayWelcomeScreen();

    // Proceed to shell
    shell();
}

extern "C" void start_login() {
    login();
}
