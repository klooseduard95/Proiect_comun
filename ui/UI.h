//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#ifndef MAIN_UI_H
#define MAIN_UI_H

#include "UserManagementUI.h"

class UI {
private:
    UserManagementUI& userManagementUI;

public:
    explicit UI(UserManagementUI& userManagementUI);

    void run();
};

#endif // MAIN_UI_H


