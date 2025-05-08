#pragma once
#include <string>
#include "../../domain/Order.h"

class EmployeeValidator {
public:
    static bool canModifyOrder(const Order& order, const std::string& employeeEmail);

    static bool canCompleteOrder(const Order& order);

    static bool canTakeOverOrder(const Order& order, const std::string& employeeEmail);

    static bool canConfirmOrder(const Order& order);
};
