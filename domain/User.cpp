//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "User.h"

User::User(const string &email, const string &password, const string &role)
    : email(email), password(password), role(role) {}

// Getters
string User::getEmail() const {
    return email;
}

string User::getPassword() const {
    return password;
}

string User::getRole() const {
    return role;
}