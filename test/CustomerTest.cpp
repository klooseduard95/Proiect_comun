//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//

#include <gtest/gtest.h>
#include "../domain/Customer.h"
#include "../repository/InMemoryRepository.h"

// Test clasa Customer - constructor, getter, setter GDPR flag
TEST(CustomerTests, CreateAndAccessCustomer) {
    Customer cust("maria@example.com", "pwd123", "Maria", "Popescu",
                  "Strada 1", "Important client", false);

    EXPECT_EQ(cust.getEmail(), "maria@example.com");
    EXPECT_EQ(cust.getFirstName(), "Maria");
    EXPECT_EQ(cust.getLastName(), "Popescu");
    EXPECT_EQ(cust.getAddress(), "Strada 1");
    EXPECT_EQ(cust.getNote(), "Important client");
    EXPECT_FALSE(cust.isGdprDeleted());

    cust.setGdprDeleted(true);
    EXPECT_TRUE(cust.isGdprDeleted());
}

// Test repository pentru Customer - add, getById, update, remove
TEST(CustomerRepositoryTests, AddGetUpdateRemove) {
    InMemoryRepository<Customer> repo;

    Customer cust1("alex@example.com", "pass789", "Alex", "Ionescu", "Strada 2", "Note", false);

    repo.add(cust1);
    auto retrieved = repo.getById("alex@example.com");
    EXPECT_EQ(retrieved.getFirstName(), "Alex");

    // Update GDPR flag
    cust1.setGdprDeleted(true);
    repo.update(cust1);
    auto updated = repo.getById("alex@example.com");
    EXPECT_TRUE(updated.isGdprDeleted());

    // Remove
    repo.remove("alex@example.com");
    EXPECT_THROW(repo.getById("alex@example.com"), std::runtime_error);
}

