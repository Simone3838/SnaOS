#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h> // For _getch() on Windows systems

// Constants for screen dimensions
const int WIDTH = 40;
const int HEIGHT = 20;

// Function to clear the screen (platform dependent)
void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

// Function to move the cursor to a specific position
void moveCursor(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

// Function to draw the cursor sprite
void drawCursor(int x, int y) {
    moveCursor(x, y);
    std::cout << 'O';  // Display the cursor
}

// Function to simulate a graphical cursor sprite
void cursorSprite() {
    int x = WIDTH / 2;
    int y = HEIGHT / 2;

    while (true) {
        clearScreen();
        drawCursor(x, y);

        // Wait for user input and handle cursor movement
        char input = _getch();

        // Detect arrow keys (Windows specific)
        if (input == 0 || input == 224) {
            input = _getch();  // Get the actual arrow key code

            switch (input) {
                case 72: // Up arrow key
                    if (y > 1) y--;
                    break;
                case 80: // Down arrow key
                    if (y < HEIGHT) y++;
                    break;
                case 75: // Left arrow key
                    if (x > 1) x--;
                    break;
                case 77: // Right arrow key
                    if (x < WIDTH) x++;
                    break;
            }
        }

        if (input == 'q') {
            break;  // Exit the loop if 'q' is pressed
        }
    }
}

extern "C" void start_cursor_sprite() {
    cursorSprite();
}
