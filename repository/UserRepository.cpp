//
// Created by adeli on 4/29/2025.
//

#include "UserRepository.h"

#include <stdexcept>

User UserRepository::findByEmail(const std::string& email) const {
    for (const auto& user : this->getAll()) {
        if (user.getEmail() == email) {
            return user;
        }
    }
    throw std::runtime_error("User not found with given email.");
}