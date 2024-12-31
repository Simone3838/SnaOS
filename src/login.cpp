#include <iostream>
#include <string>

// Function to simulate user login
bool login() {
    std::string username;
    std::string password;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    // Hardcoded credentials for demonstration purposes
    const std::string correct_username = "simone";
    const std::string correct_password = "1234";

    if (username == correct_username && password == correct_password) {
        std::cout << "Login successful!" << std::endl;
        return true;
    } else {
        std::cout << "Login failed. Incorrect username or password." << std::endl;
        return false;
    }
}

extern "C" void login_shell() {
    while (!login()) {
        // Retry login
    }

    // Once logged in, proceed to the shell
    shell();
}
