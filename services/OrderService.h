#pragma once
#include "IOrderService.h"
#include <unordered_map>

class OrderService : public IOrderService {
private:
    std::unordered_map<int, Order> orders; // key = order number

public:
    void createReservation(const Order& order) override;
    //pentru ui:
    //if (currentUser.getRole() == "Customer") {
    //    orderService.createReservation(...);
    //} else {
    //    std::cout << "Only customers can create reservations." << std::endl;
    //}
    void confirmOrder(const std::string& orderId) override;
    void completeOrder(const std::string& orderId) override;
    void updateOrder(const Order& order) override;
    void takeOverOrder(const std::string& orderId, const std::string& employeeId) override;

    std::vector<Order> getOrdersByStatus(OrderStatus status) const override;
    std::vector<Order> getOrdersForCustomer(const std::string& customerId) const override;
    double getTotalSumForPeriod(const std::string& year, const std::string& month = "") const override;
};
