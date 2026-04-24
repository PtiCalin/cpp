#include <iostream>

int main() {
    int choice = 0;

    while (choice != 3) {
        std::cout << "\n=== Console Skeleton ===\n";
        std::cout << "1. Option A\n";
        std::cout << "2. Option B\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "Option A selected.\n";
        } else if (choice == 2) {
            std::cout << "Option B selected.\n";
        } else if (choice != 3) {
            std::cout << "Invalid choice.\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
