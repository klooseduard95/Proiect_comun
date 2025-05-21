//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#ifndef CLIENTMANAGEMENTUI_H
#define CLIENTMANAGEMENTUI_H

#endif //CLIENTMANAGEMENTUI_H

#ifndef CUSTOMER_UI_H
#define CUSTOMER_UI_H

#include "../controller/ClientManagementController.h"

class CustomerUI {
private:
    CustomerController& controller;

    void displayMenu();
    void handleCreateCustomer();
    void handleUpdateCustomer();
    void handleDeleteCustomer();
    void handleAnonymizeCustomer();
    void handleListCustomers();
    void handleFindCustomer();

public:
    CustomerUI(CustomerController& controller);
    void run();
};

#endif
