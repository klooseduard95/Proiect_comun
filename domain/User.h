//
// Created by Eduard-Andreas Kloos on 17.04.2025.
//

#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
private:
    string email;
    string password;
    string role;
public:
    User();
    User(const string& email, const string& password, const string& role);

    string getEmail() const;
    string getId() const;
    string getPassword() const;
    string getRole() const;

    void setPassword(const string& email);
    void setRole(const string& role);

    bool operator==(const User& other) const;
};

#endif //USER_H
