//
// Created by Eduard-Andreas Kloos on 29.04.2025.
//
#pragma once
#include "interfaces/IRepository.h"
#include <unordered_map>
#include <vector>
#include <string>

#ifndef INMEMORYREPOSITORY_H
#define INMEMORYREPOSITORY_H

template <typename T>
class InMemoryRepository : public IRepository<T> {
private:
    std::unordered_map<std::string, T> storage;

public:
    void add(const T& entity) override;
    void update(const T& entity) override;
    void remove(const std::string& id) override;
    T getById(const std::string& id) const override;
    std::vector<T> getAll() const override;
};

#endif // INMEMORYREPOSITORY_H

