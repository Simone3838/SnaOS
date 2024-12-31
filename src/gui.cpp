#include <iostream>
#include <thread>
#include <chrono>

// Function to clear the screen (platform dependent)
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

// Function to draw a window with title and content
void drawWindow(int x, int y, int width, int height, const std::string& title, const std::string& content) {
    // Draw top border
    std::cout << "\033[" << y << ";" << x << "H" << "+" << std::string(width - 2, '-') << "+";
    
    // Draw title
    std::cout << "\033[" << y << ";" << (x + (width - title.length()) / 2) << "H" << title;
    
    // Draw side borders and content
    for (int i = 1; i < height - 1; ++i) {
        std::cout << "\033[" << (y + i) << ";" << x << "H" << "|";
        std::cout << "\033[" << (y + i) << ";" << (x + width - 1) << "H" << "|";
        if (i == 1) {
            std::cout << "\033[" << (y + i) << ";" << (x + 2) << "H" << content;
        }
    }
    
    // Draw bottom border
    std::cout << "\033[" << (y + height - 1) << ";" << x << "H" << "+" << std::string(width - 2, '-') << "+";
}

// Function to simulate a basic GUI
void gui() {
    clearScreen();
    
    // Draw main window
    drawWindow(5, 2, 40, 10, "Main Window", "Welcome to SnaOS!");
    
    // Draw button
    drawWindow(10, 14, 20, 3, "", "[ OK ]");
    
    // Wait for user input
    std::cin.get();
}

extern "C" void start_gui() {
    gui();
}
