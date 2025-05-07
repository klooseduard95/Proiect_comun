//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#ifndef USERMANAGEMENTCONTROLLER_H
#define USERMANAGEMENTCONTROLLER_H

#pragma once
#include "../services/UserService.h"

class UserManagementController {
private:
    UserService& userService;

public:
    UserManagementController(UserService& service);
    User loginUser(const std::string& email, const std::string& password);
};

#endif //USERMANAGEMENTCONTROLLER_H
