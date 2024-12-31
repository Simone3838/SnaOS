#include <iostream>
#include <string>
#include <sstream>

// Function to display the sheep ASCII art with a message
void sheepsay(const std::string& message) {
    std::cout << "  " << std::string(message.length() + 2, '_') << std::endl;
    std::cout << "< " << message << " >" << std::endl;
    std::cout << "  " << std::string(message.length() + 2, '-') << std::endl;
    std::cout << "        \\   ^__^" << std::endl;
    std::cout << "         \\  (oo)\\_______" << std::endl;
    std::cout << "            (__)\\       )\\/\\" << std::endl;
    std::cout << "                ||----w |" << std::endl;
    std::cout << "                ||     ||" << std::endl;
}

// Entry point for the sheepsay command
extern "C" void start_sheepsay() {
    std::string message;
    std::cout << "Enter your message: ";
    std::getline(std::cin, message);
    sheepsay(message);
}
