//
// Created by adeli on 4/29/2025.
//

#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#pragma once

#include "InMemoryRepository.h"
#include "../domain/User.h"

class UserRepository: public InMemoryRepository<User> {
public:
  User findByEmail(const std::string& email) const;
};



#endif //USERREPOSITORY_H
