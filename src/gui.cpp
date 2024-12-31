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

// Function to draw a button
void drawButton(int x, int y, const std::string& label, bool pressed) {
    std::string button = "[ " + label + " ]";
    if (pressed) {
        button = "[*" + label + "*]";
    }
    std::cout << "\033[" << y << ";" << x << "H" << button;
}

// Function to simulate a basic GUI with a button test
void gui() {
    clearScreen();
    
    // Draw main window
    drawWindow(5, 2, 40, 10, "Main Window", "Press Enter to press the button");
    
    // Draw button
    bool buttonPressed = false;
    drawButton(20, 14, "OK", buttonPressed);
    
    // Wait for user input and handle button press
    char input;
    while (true) {
        input = std::cin.get();
        if (input == '\n') {
            buttonPressed = !buttonPressed;
            drawButton(20, 14, "OK", buttonPressed);
        }
    }
}

extern "C" void start_gui() {
    gui();
}
