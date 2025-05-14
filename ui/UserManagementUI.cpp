//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "UserManagementUI.h"
#include <iostream>

UserManagementUI::UserManagementUI(UserManagementController& controller)
    : controller(controller) {}

void UserManagementUI::startLoginFlow() {
    std::string email, password;
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Password: ";
    std::getline(std::cin, password);

    try {
        User loggedInUser = controller.loginUser(email, password);
        std::cout << "\nLogin successful! Welcome, " << loggedInUser.getEmail() << ".\n";
        showUserMenu(loggedInUser);
    } catch (const std::exception& e) {
        std::cerr << "Login failed: " << e.what() << "\n";
    }
}

// Role-Based User Menu
void UserManagementUI::showUserMenu(const User& user) {
    std::cout << "\n--- User Menu ---\n";

    if (user.getRole() == "employee") {
        std::cout << "1. Manage Customers\n";
        std::cout << "2. Manage Products\n";
        std::cout << "3. View Products\n";
    }
    else if (user.getRole() == "customer") {
        std::cout << "1. View Products\n";
        std::cout << "2. Modify Profile\n";
        std::cout << "3. Create Reservations\n";
    }
    else {
        std::cout << "Invalid user role.\n";
        return;
    }

    // User selects an option
    int choice;
    std::cout << "\nEnter your choice: ";
    std::cin >> choice;

    // Depending on choice, redirect (placeholder for now)
    switch (choice) {
        case 1:
            std::cout << "Option 1 selected.\n";
            break;
        case 2:
            std::cout << "Option 2 selected.\n";
            break;
        case 3:
            std::cout << "Option 3 selected.\n";
            break;
        default:
            std::cout << "Invalid option.\n";
            break;
    }
}

