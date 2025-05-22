//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#include "User.h"

User::User() : email(""), password(""), role("") {}

User::User(const string &email, const string &password, const string &role)
    : email(email), password(password), role(role) {}

// Getters
string User::getEmail() const {
    return email;
}

string User::getId() const {
    return email;
}

string User::getPassword() const {
    return password;
}

string User::getRole() const {
    return role;
}

void User::setPassword(const string &password) {
    this->password = password;
}

void User::setRole(const string &role) {
    this->role = role;
}

bool User::operator==(const User& other) const {
    return email == other.email && password == other.password && role == other.role;
}
