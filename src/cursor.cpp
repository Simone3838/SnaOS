#include <iostream>
#include <conio.h> // For _getch() and _kbhit() on Windows systems

// Constants for cursor movement
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

// Function to simulate cursor movement
void cursorMovement() {
    int x = WIDTH / 2;
    int y = HEIGHT / 2;

    while (true) {
        clearScreen();
        moveCursor(x, y);
        std::cout << 'X';  // Display the cursor

        // Display instructions
        moveCursor(0, HEIGHT + 1);
        std::cout << "Use arrow keys to move the cursor. Press 'q' to quit.";

        char ch = _getch();

        if (ch == 'q') {
            break;  // Exit the loop if 'q' is pressed
        }

        // Detect arrow keys (Windows specific)
        if (ch == 0 || ch == 224) {
            switch (_getch()) {
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
    }
}

extern "C" void start_cursor() {
    cursorMovement();
}
