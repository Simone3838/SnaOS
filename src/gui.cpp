#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h> // For _getch() and _kbhit() on Windows systems

// Constants for window size
const int WIDTH = 40;
const int HEIGHT = 10;

// Function to clear the screen (platform dependent)
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

// Function to move the cursor to a specific position
void moveCursor(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
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

// Function to simulate a basic GUI with a cursor
void gui() {
    int cursorX = 20;
    int cursorY = 6;

    clearScreen();
    
    // Draw main window
    drawWindow(5, 2, WIDTH, HEIGHT, "Main Window", "Use arrow keys to move the cursor.");
    
    // Draw button
    bool buttonPressed = false;
    drawButton(20, 14, "OK", buttonPressed);
    
    // Display cursor
    moveCursor(cursorX, cursorY);
    std::cout << 'X';  // Display the cursor

    // Wait for user input and handle cursor movement
    char input;
    while (true) {
        input = _getch();

        // Detect arrow keys (Windows specific)
        if (input == 0 || input == 224) {
            input = _getch();  // Get the actual arrow key code
            moveCursor(cursorX, cursorY);
            std::cout << ' ';  // Clear the old cursor position

            switch (input) {
                case 72: // Up arrow key
                    if (cursorY > 3) cursorY--;
                    break;
                case 80: // Down arrow key
                    if (cursorY < HEIGHT) cursorY++;
                    break;
                case 75: // Left arrow key
                    if (cursorX > 6) cursorX--;
                    break;
                case 77: // Right arrow key
                    if (cursorX < WIDTH + 4) cursorX++;
                    break;
            }

            moveCursor(cursorX, cursorY);
            std::cout << 'X';  // Display the cursor at the new position
        }

        if (input == 'q') {
            break;  // Exit the loop if 'q' is pressed
        }
    }
}

extern "C" void start_gui() {
    gui();
}
