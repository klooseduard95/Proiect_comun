//
// Created by Eduard-Andreas Kloos on 20.05.2025.
//
#include <gtest/gtest.h>
#include "../domain/Employee.h"
#include "../repository/InMemoryRepository.h"

/**
 * @brief Testeaza constructorul si metodele de acces pentru clasa Employee.
 *
 * Verifica initializarea corecta a unui obiect Employee si functionalitatea getter-elor si setter-ului pentru salariu.
 */
TEST(EmployeeTests, CreateAndAccessEmployee) {
    Employee emp("john.doe@example.com", "pass123", "John", "Doe", "Developer", "1990-01-01", 5000.0);

    EXPECT_EQ(emp.getEmail(), "john.doe@example.com");
    EXPECT_EQ(emp.getFirstName(), "John");
    EXPECT_EQ(emp.getLastName(), "Doe");
    EXPECT_EQ(emp.getPosition(), "Developer");
    EXPECT_EQ(emp.getBirthDate(), "1990-01-01");
    EXPECT_DOUBLE_EQ(emp.getSalary(), 5000.0);

    emp.setSalary(5500.0);
    EXPECT_DOUBLE_EQ(emp.getSalary(), 5500.0);
}

/**
 * @brief Testeaza functionalitatile repository-ului in memorie pentru Customer.
 *
 * Verifica operatiile add, getById, update si remove pentru obiecte de tip Customer.
 */
TEST(EmployeeRepositoryTests, AddGetUpdateRemove) {
    InMemoryRepository<Employee> repo;

    Employee emp1("jane.doe@example.com", "pass456", "Jane", "Doe", "Manager", "1985-05-10", 7000.0);

    // Adaugare
    repo.add(emp1);
    auto retrieved = repo.getById("jane.doe@example.com");
    EXPECT_EQ(retrieved.getFirstName(), "Jane");

    // Update salariu
    emp1.setSalary(7500.0);
    repo.update(emp1);
    auto updated = repo.getById("jane.doe@example.com");
    EXPECT_DOUBLE_EQ(updated.getSalary(), 7500.0);

    // Remove
    repo.remove("jane.doe@example.com");
    EXPECT_THROW(repo.getById("jane.doe@example.com"), std::runtime_error);
}
