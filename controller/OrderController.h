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
    void confirmOrder(const std::string& orderId);
    void completeOrder(const std::string& orderId);
    void updateOrder(const Order& order);
    void takeOverOrder(const std::string& orderId, const std::string& employeeId);

    vector<Order> getOrdersByStatus(OrderStatus status) const;
    vector<Order> getOrdersForCustomer(const std::string& customerId) const;
    double getTotalSumForPeriod(const std::string& year, const std::string& month = "") const;

    Order getOrderById(const std::string& orderId) const;
};
