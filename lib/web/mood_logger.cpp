#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // Check for command line arguments
    if (argc < 2) {
        std::cerr << "Error: No mood received." << std::endl;
        return EXIT_FAILURE;
    }
    
    // Convert first argument to string for safer handling
    std::string mood(argv[1]);
    
    // Output the received mood
    std::cout << "Button Pressed: " << mood << std::endl;
    
    return EXIT_SUCCESS;
}
