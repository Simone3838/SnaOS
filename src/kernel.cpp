#include <iostream>

// Function to set the background color to green
void setBackgroundColor() {
    // Set background color to green (color attribute 0x20)
    std::cout << "\033[42m"; // ANSI escape code for green background
}

// Kernel main function
extern "C" void kernel_main() {
    setBackgroundColor();

    // Display a message to confirm the background color has been set
    std::cout << "Background color set to green!" << std::endl;

    // Continue with the rest of the kernel initialization
    login_shell()
    while(1)
}
