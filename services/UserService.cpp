//
// Created by adeli on 4/29/2025.
//

#include "UserService.h"
#include <stdexcept>

UserService::UserService(UserRepository& repo) : userRepo(repo) {}

User UserService::login(const std::string& email, const std::string& password) {
    User user = userRepo.findByEmail(email);
    if (user.getPassword() != password) {
        throw std::runtime_error("Invalid credentials");
    }
    return user;
}
