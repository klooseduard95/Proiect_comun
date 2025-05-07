//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "UserManagementController.h"

UserManagementController::UserManagementController(UserService& service)
    : userService(service) {}

User UserManagementController::loginUser(const std::string& email, const std::string& password) {
    return userService.login(email, password);
}