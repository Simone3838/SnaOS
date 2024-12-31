extern "C" void kernel_main() {
    // Initialize video memory (printing "Hello, SnaOS!" is optional now)
    const char* str = "Hello, SnaOS!";
    char* video_memory = (char*)0xb8000;
    int offset = 0;

    while (*str != 0) {
        video_memory[offset] = *str++;
        video_memory[offset + 1] = 0x07; // Attribute byte: light gray on black
        offset += 2;
    }

    // Call the shell
    shell();
    
    while (1); // Hang to keep the kernel running
}
