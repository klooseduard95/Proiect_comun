//
// Created by Eduard-Andreas Kloos on 29.04.2025.
//

#pragma once
#include <vector>
#ifndef IREPOSITORY_H
#define IREPOSITORY_H

template <typename T>
class IRepository {
public:
    virtual void add(const T& entity) = 0;
    virtual void update(const T& entity) = 0;
    virtual void remove(const std::string& id) = 0;
    virtual T getById(const std::string& id) const = 0;
    virtual std::vector<T> getAll() const = 0;
    virtual ~IRepository() = default;
};

#endif //IREPOSITORY_H
