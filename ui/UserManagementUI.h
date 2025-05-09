//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#ifndef USERMANAGEMENTUI_H
#define USERMANAGEMENTUI_H

#pragma once
#include "../controller/UserManagementController.h"

class UserManagementUI {
private:
    UserManagementController& controller;

public:
    UserManagementUI(UserManagementController& controller);
    void startLoginFlow();  // this will be used by main() to start login
};
#endif //USERMANAGEMENTUI_H
