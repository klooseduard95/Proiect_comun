#ifndef ORDERMANAGEMENTUI_H
#define ORDERMANAGEMENTUI_H

#include "../controller/OrderController.h"
#include "../controller/ProductController.h"
#include "../domain/User.h"

class OrderManagementUI {
private:
    OrderController& orderController;
    ProductController& productController;

    void printOrdersWithIndex(const std::vector<Order>& orders) const;
    int getUserChoice() const;

public:
    OrderManagementUI(OrderController& controller, ProductController& productCtrl);

    void showManageOrdersMenu(const User& employee);
    void showCustomerOrders(const User& customer);

    void showCreateReservationMenu(const Customer &customer);
};

#endif
