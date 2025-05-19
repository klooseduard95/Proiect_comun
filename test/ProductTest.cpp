//
// Created by adeli on 5/15/2025.
//

#include <gtest/gtest.h>
#include "../domain/Product.h"
#include "../domain/Validations/ProductValidator.h"
#include <stdexcept>

// Test correct creation of a valid product
TEST(ProductTest, ValidProductCreation) {
    Product p("P001", "Laptop", 1500.0, 10);
    EXPECT_NO_THROW(ProductValidator::validateForCreate(p));
    EXPECT_EQ(p.getId(), "P001");
    EXPECT_EQ(p.getName(), "Laptop");
    EXPECT_DOUBLE_EQ(p.getPrice(), 1500.0);
    EXPECT_EQ(p.getStock(), 10);
}

// Test product creation with invalid price (negative)
TEST(ProductTest, InvalidPriceThrows) {
    Product p("P002", "Phone", -10.0, 5);
    EXPECT_THROW(ProductValidator::validateForCreate(p), std::invalid_argument);
}

// Test product creation with invalid stock (negative)
TEST(ProductTest, InvalidStockThrows) {
    Product p("P003", "Tablet", 300.0, -1);
    EXPECT_THROW(ProductValidator::validateForCreate(p), std::invalid_argument);
}

// Test product creation with empty product ID
TEST(ProductTest, EmptyIdThrows) {
    Product p("", "Monitor", 200.0, 2);
    EXPECT_THROW(ProductValidator::validateForCreate(p), std::invalid_argument);
}

// Test product creation with empty name
TEST(ProductTest, EmptyNameThrows) {
    Product p("P004", "", 200.0, 2);
    EXPECT_THROW(ProductValidator::validateForCreate(p), std::invalid_argument);
}
