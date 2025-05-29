#include <gtest/gtest.h>
#include <stdexcept>
#include "../domain/User.h"
#include "../domain/Validations/UserValidator.h"
#include "../repository/UserRepository.h"
#include "../repository/InMemoryRepository.h"


/**
 * @test UserTests.CreateAccessUpdateUser
 * @brief Tests creation, access, and update functionality for the User class.
 *
 * Verifies that the User object:
 * - Is initialized correctly via the constructor.
 * - Provides correct values through getter methods.
 * - Allows updates to password and role through setters.
 */
TEST(UserTests, CreateAccessUpdateUser ) {
    User user("mihai@gmail.com", "Mihai","Employee");
    EXPECT_EQ(user.getEmail(), "mihai@gmail.com");
    EXPECT_EQ(user.getId(), "mihai@gmail.com");
    EXPECT_EQ(user.getPassword(), "Mihai");
    EXPECT_EQ(user.getRole(), "Employee");
    user.setPassword("Jarda");
    user.setRole("Costumer");
    EXPECT_EQ(user.getPassword(), "Jarda");
    EXPECT_EQ(user.getRole(), "Costumer");
}

/**
 * @test UserValidatorTest.ValidateUserRole
 * @brief Tests the role validation methods in UserValidator.
 *
 * Ensures that:
 * - `isEmployee` returns true for "Employee" role.
 * - `isCustomer` returns false for "Employee" role.
 */
TEST(UserValidatorTest, ValidateUserRole) {
    UserValidator validator;
    User user1("mihai@gmail.com", "Mihai","Employee");
    EXPECT_TRUE(validator.isEmployee(user1.getRole()));
    EXPECT_FALSE(validator.isCustomer(user1.getRole()));
}


/**
 * @test UserRepositoryTest.ValidateGetByEmail
 * @brief Tests add, update, and remove operations in UserRepository.
 *
 * Test flow:
 * - Add a user and validate retrieval by email.
 * - Update the user and confirm the changes via findByEmail.
 * - Remove the user and expect an exception when retrieving.
 *
 * @throws std::runtime_error If user is not found after removal.
 */
TEST(UserRepositoryTest, ValidateGetByEmail) {
    User user("mihai@gmail.com", "Mihai","Employee");
    User user1("mihai@gmail.com", "Jarda","Costumer");
    UserRepository repo;
    repo.add(user);
    EXPECT_EQ(repo.findByEmail(user.getEmail()), user);
    repo.update(user1);
    EXPECT_EQ(repo.findByEmail(user.getEmail()), user1);
    repo.remove(user.getEmail());
    EXPECT_THROW(repo.findByEmail(user.getEmail()), std::runtime_error);

}