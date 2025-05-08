#pragma once
#include <string>

class UserValidator {
public:
    static bool isEmployee(const std::string& role);
    static bool isCustomer(const std::string& role);
};
