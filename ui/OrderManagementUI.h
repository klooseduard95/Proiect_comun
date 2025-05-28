#ifndef ORDERMANAGEMENTUI_H
#define ORDERMANAGEMENTUI_H

#include "../controller/OrderController.h"
#include "../domain/User.h"

class OrderManagementUI {
private:
    OrderController& orderController;

    void printOrdersWithIndex(const std::vector<Order>& orders) const;
    int getUserChoice() const;

public:
    OrderManagementUI(OrderController& controller);

    void showManageOrdersMenu(const User& employee);
    void showCustomerOrders(const User& customer);

    void showCreateReservationMenu(const User &customer);
};

#endif
