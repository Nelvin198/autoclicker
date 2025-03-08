#include <iostream>
#include <windows.h>
#include <thread>
#include <atomic>

// Global variables
std::atomic<bool> isClicking(false);
int clickInterval = 100; // Default interval in milliseconds
bool doubleClickEnabled = false;

// Function to simulate mouse click
void PerformClick() {
    // Simulate mouse down and up events
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

    if (doubleClickEnabled) {
        // Simulate a second click for double-click
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    }
}

// Auto-clicker loop
void AutoClickerLoop() {
    while (true) {
        if (isClicking) {
            PerformClick();
            std::this_thread::sleep_for(std::chrono::milliseconds(clickInterval));
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Sleep to reduce CPU usage
        }
    }
}

// Function to display the menu
void DisplayMenu() {
    std::cout << "AutoClicker - C++" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "1. Start/Stop AutoClicker" << std::endl;
    std::cout << "2. Set Click Interval (Current: " << clickInterval << " ms)" << std::endl;
    std::cout << "3. Toggle Double Click (Current: " << (doubleClickEnabled ? "Enabled" : "Disabled") << ")" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    // Start the auto-clicker thread
    std::thread clickerThread(AutoClickerLoop);
    clickerThread.detach(); // Detach the thread to run independently

    int choice;
    while (true) {
        DisplayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                isClicking = !isClicking;
                std::cout << "AutoClicker " << (isClicking ? "Started" : "Stopped") << std::endl;
                break;

            case 2:
                std::cout << "Enter new click interval (in milliseconds): ";
                std::cin >> clickInterval;
                std::cout << "Click interval set to " << clickInterval << " ms" << std::endl;
                break;

            case 3:
                doubleClickEnabled = !doubleClickEnabled;
                std::cout << "Double Click " << (doubleClickEnabled ? "Enabled" : "Disabled") << std::endl;
                break;

            case 4:
                std::cout << "Exiting..." << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}