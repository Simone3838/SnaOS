#include <iostream>
#include <thread>
#include <chrono>

const int width = 20;   // Width of the boundary
const int height = 10;  // Height of the boundary

void clearScreen() {
    // Clear the screen (platform dependent)
    std::cout << "\033[2J\033[1;1H";
}

void drawBall(int x, int y) {
    // Draw the boundary and ball
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                std::cout << "#";  // Boundary
            } else if (i == y && j == x) {
                std::cout << "O";  // Ball
            } else {
                std::cout << " ";  // Empty space
            }
        }
        std::cout << std::endl;
    }
}

void bouncingBall() {
    int x = width / 2, y = height / 2;  // Initial position of the ball
    int dx = 1, dy = 1;                 // Direction of the ball

    while (true) {
        clearScreen();
        drawBall(x, y);

        // Update ball position
        x += dx;
        y += dy;

        // Check for collision with the boundary
        if (x <= 1 || x >= width - 2) dx = -dx;
        if (y <= 1 || y >= height - 2) dy = -dy;

        // Delay to control the speed of the ball
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

extern "C" void bouncing_ball() {
    bouncingBall();
}
