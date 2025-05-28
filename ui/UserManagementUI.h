//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#ifndef USERMANAGEMENTUI_H
#define USERMANAGEMENTUI_H

#pragma once
#include "../controller/UserManagementController.h"
#include "../controller/ProductController.h"
#include "../controller/OrderController.h"
#include "../controller/ClientManagementController.h"
#include "../ui/ClientManagementUI.h"
#include "../ui/ProductManagementUI.h"
#include "../ui/OrderManagementUI.h"

class UserManagementUI {
private:
    UserManagementController& userController;
    ProductController& productController;
    OrderController& orderController;
    CustomerController& customerController;
    CustomerUI& customerUI;
    ProductUI& productUI;
    OrderManagementUI& orderUI;

    User loggedInUser;

    void showUserMenu(const User& user);
    void showEmployeeMenu();
    void showCustomerMenu();
    int getUserChoice();
    string getNewPassword();

public:
    UserManagementUI(UserManagementController& controller, ProductController& productController, OrderController& orderController, CustomerController& customerController, CustomerUI& customerUI, ProductUI& productUI, OrderManagementUI& orderUI);
    void startLoginFlow();
};
#endif //USERMANAGEMENTUI_H
