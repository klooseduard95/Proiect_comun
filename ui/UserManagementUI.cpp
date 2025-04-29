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
        // std::cout << "Login successful! Welcome, " << loggedInUser.getFirstName() << ".\n";
        // Optionally redirect to role-based UI menu
    } catch (const std::exception& e) {
        std::cerr << "Login failed: " << e.what() << "\n";
    }
}

