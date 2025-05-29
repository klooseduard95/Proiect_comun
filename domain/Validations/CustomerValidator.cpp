//
// Created by Eduard-Andreas Kloos on 29.04.2025.
//

#include "CustomerValidator.h"
#include "stdexcept"
#include <string>
#include <regex>
#include "../repository/InMemoryRepository.h"

using namespace std;

/**
 * @brief Constructs a CustomerValidator with access to a customer repository.
 *
 * @param repo Pointer to a repository containing Customer objects. Used for validation checks like duplicate emails.
 */
CustomerValidator::CustomerValidator(IRepository<Customer> *repo) {
    customerRepository = repo;
}

/**
 * @brief Validates the email of a given customer.
 *
 * Performs the following checks:
 * - Ensures the email format is valid using a regular expression.
 * - Checks if the email already exists in the repository.
 *
 * @param customer The Customer object whose email needs to be validated.
 *
 * @throws std::invalid_argument If the email format is invalid or already exists in the repository.
 */
void CustomerValidator::ValidateEmail(const Customer &customer) {
    if (std::regex pattern(R"(\w+@\w+\.\w+)"); !regex_match(customer.getEmail(), pattern)) {
        throw invalid_argument ("Invalid email format.");
    }
    auto customer2 = this->customerRepository->getById(customer.getId());
    if (customer2.getEmail() == customer.getEmail()) {
        throw invalid_argument ("Email already exists.");
    }
};

/**
 * @brief Validates the GDPR-related fields of a customer.
 *
 * - If the customer is GDPR deleted, all fields (first name, last name, address) must be completed.
 * - Otherwise, only first name and last name are required.
 *
 * @param customer The Customer object whose GDPR-related data should be validated.
 *
 * @throws std::invalid_argument If the required fields are not completed based on the GDPR flag.
 */
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