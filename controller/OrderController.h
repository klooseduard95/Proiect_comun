#pragma once

using namespace std;
#include "Order.h"
#include "../repository/interfaces/IRepository.h"  // IRepository<Order>
#include <string>
#include <vector>

class OrderController {
private:
    IRepository<Order>& orderRepo;

public:
    explicit OrderController(IRepository<Order>& repo);

    void createReservation(const User& user, const Order& order);
    void confirmOrder(const string& orderId);
    void completeOrder(const string& orderId);
    void updateOrder(const User& user, const Order& updatedOrder);
    void takeOverOrder(const User& user, const string& orderId);

    vector<Order> getOrdersByStatus(OrderStatus status) const;
    vector<Order> getOrdersForCustomer(const User& user) const;
    double getTotalSumForPeriod(const string& year, const string& month) const;
    Order getOrderById(const string& orderId) const;
};
