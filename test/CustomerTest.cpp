//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//

#include <gtest/gtest.h>
#include "../domain/Customer.h"
#include "../repository/InMemoryRepository.h"

/**
 * @brief Testeaza constructorul si metodele de acces pentru clasa Customer.
 *
 * Verifica initializarea unui obiect Customer, inclusiv flag-ul GDPR, si functionalitatea getter-elor si setter-ului.
 */
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

/**
 * @brief Testeaza functionalitatile repository-ului in memorie pentru Customer.
 *
 * Verifica operatiile add, getById, update si remove pentru obiecte de tip Customer.
 */
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

