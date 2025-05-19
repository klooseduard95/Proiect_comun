#include "ProductValidator.h"

void ProductValidator::validateForCreate(const Product& product) {
    // Specific validation for creation (Product ID should not be empty)
    if (product.getId().empty())
        throw std::invalid_argument("Product ID cannot be empty.");

    // Common validations for both create and update
    validateCommon(product);
}

void ProductValidator::validateForUpdate(const Product& product) {
    // No specific checks for update (ID can be empty as it shouldn't change)

    // Common validations for both create and update
    validateCommon(product);
}

void ProductValidator::validateCommon(const Product& product) {
    // Validate Product ID format - Only letters/numbers
    if (!product.getId().empty() && !std::regex_match(product.getId(), std::regex("^[A-Za-z0-9]+$")))
        throw std::invalid_argument("Product ID can only contain letters and numbers.");

    // Validate Product Name - Non-empty
    if (product.getName().empty())
        throw std::invalid_argument("Product name cannot be empty.");

    // Validate Price - Non-negative
    if (product.getPrice() < 0)
        throw std::invalid_argument("Product price cannot be negative.");

    // Validate Stock - Non-negative
    if (product.getStock() < 0)
        throw std::invalid_argument("Product stock cannot be negative.");
}

