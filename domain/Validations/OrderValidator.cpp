//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//

#include "OrderValidator.h"

void OrderValidator::validateStatusForReservation(const Order& order) {
    if (order.getStatus() != OrderStatus::Reservation) {
        throw std::runtime_error("Order status must be Reservation when creating a reservation.");
    }
}

void OrderValidator::validateBeforeConfirm(const Order& order) {
    if (order.getStatus() == OrderStatus::Completed) {
        throw std::runtime_error("Cannot confirm a completed order.");
    }
}

void OrderValidator::validateBeforeComplete(const Order& order) {
    if (order.getStatus() == OrderStatus::Completed) {
        throw std::runtime_error("Order is already completed.");
    }
    if (order.getStatus() != OrderStatus::Confirmed) {
        throw std::runtime_error("Only confirmed orders can be completed.");
    }
}

void OrderValidator::validateUpdatePermission(const Order& existing, const Order& updated) {
    if (existing.getStatus() == OrderStatus::Completed) {
        throw std::runtime_error("Completed orders cannot be modified.");
    }
    if (existing.getEmployee().getId() != updated.getEmployee().getId()) {
        throw std::runtime_error("Employees can only update their own orders.");
    }
}


