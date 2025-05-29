//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "UI.h"
#include <iostream>

UI::UI(UserManagementUI& userManagementUI)
    : userManagementUI(userManagementUI) {}

void UI::run() {
    std::cout << "Welcome to the Application!\n";
    std::cout << "Please log in to continue.\n";
    userManagementUI.startLoginFlow();
}


