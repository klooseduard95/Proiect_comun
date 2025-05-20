//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//

#pragma once
#include "Order.h"
#include <stdexcept>

class OrderValidator {
public:
    static void validateStatusForReservation(const Order& order);
    static void validateBeforeConfirm(const Order& order);
    static void validateBeforeComplete(const Order& order);
    static void validateUpdatePermission(const Order& existing, const Order& updated);
};

