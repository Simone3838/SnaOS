#include <iostream>
#include <thread>
#include <chrono>

// Function to simulate a clock
extern "C" void clock() {
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    while (true) {
        // Clear the screen (simulated)
        std::cout << "\033[2J\033[1;1H";

        // Display the time
        std::cout << "Clock: " 
                  << (hours < 10 ? "0" : "") << hours << ":"
                  << (minutes < 10 ? "0" : "") << minutes << ":"
                  << (seconds < 10 ? "0" : "") << seconds << std::endl;

        // Wait for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // Increment the time
        seconds++;
        if (seconds == 60) {
            seconds = 0;
            minutes++;
            if (minutes == 60) {
                minutes = 0;
                hours++;
                if (hours == 24) {
                    hours = 0;
                }
            }
        }
    }
}
