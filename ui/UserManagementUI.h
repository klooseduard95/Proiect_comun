//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#ifndef USERMANAGEMENTUI_H
#define USERMANAGEMENTUI_H

#pragma once
#include "../controller/UserManagementController.h"
#include "../controller/ProductController.h"
#include "../controller/OrderController.h"
#include "../ui/ClientManagementUI.h"
#include "../ui/ProductManagementUI.h"

class UserManagementUI {
private:
    UserManagementController& controller;
    ProductController& productController;
    OrderController& orderController;
    CustomerUI& customerUI;
    ProductUI& productUI;

    void showUserMenu(const User& user);
    void showEmployeeMenu();

    void showCustomerMenu();

    int getUserChoice();

public:
    UserManagementUI(UserManagementController& controller, ProductController& productController, OrderController& orderController, CustomerUI& customerUI, ProductUI& productUI);
    void startLoginFlow();  // this will be used by main() to start login
};
#endif //USERMANAGEMENTUI_H
