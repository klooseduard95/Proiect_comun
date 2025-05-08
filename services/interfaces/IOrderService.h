#pragma once
#include <vector>
#include <string>
#include "../../domain/Order.h"
#ifndef IORDERSERVICE_H
#define IORDERSERVICE_H

class IOrderService {
public:
    virtual void createReservation(const Order& order) = 0;
    virtual void confirmOrder(const std::string& orderId) = 0;
    virtual void completeOrder(const std::string& orderId) = 0;
    virtual void updateOrder(const Order& order) = 0;
    virtual void takeOverOrder(const std::string& orderId, const std::string& employeeId) = 0;

    virtual std::vector<Order> getOrdersByStatus(OrderStatus status) const = 0;
    virtual std::vector<Order> getOrdersForCustomer(const std::string& customerId) const = 0;

    virtual double getTotalSumForPeriod(const std::string& year, const std::string& month = "") const = 0;

    virtual void updateOrder(const Order& order, const std::string& employeeId) = 0;


    virtual ~IOrderService() = default;
};

#endif //IORDERSERVICE_H
