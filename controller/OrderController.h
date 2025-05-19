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

    void createReservation(const Order& order);
    void confirmOrder(const string& orderId);
    void completeOrder(const string& orderId);
    void updateOrder(const Order& order);
    void takeOverOrder(const string& orderId, const string& employeeId);

    vector<Order> getOrdersByStatus(OrderStatus status) const;
    vector<Order> getOrdersForCustomer(const string& customerId) const;
    double getTotalSumForPeriod(const string& year, const tring& month = "") const;

    Order getOrderById(const string& orderId) const;
};
