#include <gtest/gtest.h>
#include <stdexcept>
#include "../domain/User.h"
#include "../domain/Validations/UserValidator.h"

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
