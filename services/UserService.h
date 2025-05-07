//
// Created by adeli on 4/29/2025.
//

#ifndef USERSERVICE_H
#define USERSERVICE_H

#pragma once
#include "../domain/User.h"
#include "../repository/UserRepository.h"


class UserService {
private:
    UserRepository& userRepo;

public:
    UserService(UserRepository& repo);
    User login(const std::string& email, const std::string& password);
};



#endif //USERSERVICE_H
