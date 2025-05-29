#include <gtest/gtest.h>
#include <stdexcept>
#include "../domain/User.h"
#include "../domain/Validations/UserValidator.h"
#include "../repository/UserRepository.h"
#include "../repository/InMemoryRepository.h"

//Test for User class constructor getters and setters

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

//Test for UserValidator class

TEST(UserValidatorTest, ValidateUserRole) {
    UserValidator validator;
    User user1("mihai@gmail.com", "Mihai","employee");
    EXPECT_TRUE(validator.isEmployee(user1.getRole()));
    EXPECT_FALSE(validator.isCustomer(user1.getRole()));
}

//Test for UserRepo

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