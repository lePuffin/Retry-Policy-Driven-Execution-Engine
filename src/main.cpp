/**
 * @file main.cpp
 * @brief Entry point for the application.
 * @author lePuffin
 * @copyright Copyright (c) 2026 Carlos Estevao
 * @date 2026-01-31
 */

/****** Includes ******/
#include <iostream>

/****** Defines ******/
static constexpr const char* TAG = "[Main]";

/****** Functions ******/
// Public

int main() {
    // Initialization phase: Print a message and create the TaskManager.
    std::cout << "Initializing application..." << std::endl;

    // Main execution phase: Run the task(s) and handle any errors.
    try {
        std::cout << TAG << " Application is running..." << std::endl;

        while (1) {
            // Usual application logic would go here (e.g., event loop, more tasks, etc.)
            break;  // For this example, we just break immediately
        }

    } catch (const std::exception& e) {
        // Handle known exceptions and print the error message.
        std::cerr << TAG << " An error occurred: " << e.what() << std::endl;
        return EXIT_FAILURE;

    } catch (...) {
        // Handle any other unknown exceptions.
        std::cerr << TAG << " An unknown error occurred." << std::endl;
        return EXIT_FAILURE;
    }

    // Cleanup phase: Print a message before exiting.
    std::cout << TAG << " Cleaning up and exiting..." << std::endl;

    return EXIT_SUCCESS;
}

// End of file
