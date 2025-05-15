//
// Created by Eduard-Andreas Kloos on 29.04.2025.
//
#pragma once
#include "interfaces/IRepository.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

#ifndef INMEMORYREPOSITORY_H
#define INMEMORYREPOSITORY_H

template <typename T>
class InMemoryRepository : public IRepository<T> {
private:
    std::unordered_map<std::string, T> storage;

public:
    void add(const T& entity) override {
        auto id = entity.getId();
        if (storage.find(id) != storage.end()) {
            throw std::runtime_error("Entity with ID already exists.");
        }
        storage[id] = entity;
    }

    void update(const T& entity) override {
        auto id = entity.getId();
        if (storage.find(id) == storage.end()) {
            throw std::runtime_error("Entity not found.");
        }
        storage[id] = entity;
    }

    void remove(const std::string& id) override {
        if (storage.erase(id) == 0) {
            throw std::runtime_error("Entity not found for deletion.");
        }
    }

    T getById(const std::string& id) const override {
        auto it = storage.find(id);
        if (it == storage.end()) {
            throw std::runtime_error("Entity not found.");
        }
        return it->second;
    }

    std::vector<T> getAll() const override {
        std::vector<T> result;
        for (const auto& pair : storage) {
            result.push_back(pair.second);
        }
        return result;
    }
};

#endif // INMEMORYREPOSITORY_H


