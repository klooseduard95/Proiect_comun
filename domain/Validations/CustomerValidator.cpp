//
// Created by Eduard-Andreas Kloos on 29.04.2025.
//

#include "CustomerValidator.h"
#include "stdexcept"
#include <string>
#include <regex>
#include "../repository/InMemoryRepository.h"

using namespace std;

void CustomerValidator::ValidateEmail(const Customer &customer) {
    InMemoryRepository<Customer> repository;
    if (std::regex pattern(R"(\w+@\w+\.\w+)"); !regex_match(customer.getEmail(), pattern)) {
        throw invalid_argument ("Invalid email format.");
    }
    auto customer2 = repository.getById(customer.getId());
    if (customer2.getEmail() == customer.getEmail()) {
        throw invalid_argument ("Email already exists.");
    }
};

void CustomerValidator::ValidateGdpr(const Customer &customer) {
    if (customer.isGdprDeleted()) {
        if (customer.getFirstName().empty() || customer.getLastName().empty() || customer.getAddress().empty()) {
            throw invalid_argument ("All fields need to be completed.");
        }
    }
    else {
        if (customer.getFirstName().empty() || customer.getLastName().empty()) {
            throw invalid_argument ("First and lastname need to be completed.");
        }
    }
}