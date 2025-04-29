//
// Created by Eduard-Andreas Kloos on 29.04.2025.
//

#include "InMemoryRepository.h"
#pragma once
#include <stdexcept>

template <typename T>
void InMemoryRepository<T>::add(const T& entity) {
    auto id = entity.getId();
    if (storage.find(id) != storage.end()) {
        throw std::runtime_error("Entity with ID already exists.");
    }
    storage[id] = entity;
}

template <typename T>
void InMemoryRepository<T>::update(const T& entity) {
    auto id = entity.getId();
    if (storage.find(id) == storage.end()) {
        throw std::runtime_error("Entity not found.");
    }
    storage[id] = entity;
}

template <typename T>
void InMemoryRepository<T>::remove(const std::string& id) {
    if (storage.erase(id) == 0) {
        throw std::runtime_error("Entity not found for deletion.");
    }
}

template <typename T>
T InMemoryRepository<T>::getById(const std::string& id) const {
    auto it = storage.find(id);
    if (it == storage.end()) {
        throw std::runtime_error("Entity not found.");
    }
    return it->second;
}

template <typename T>
std::vector<T> InMemoryRepository<T>::getAll() const {
    std::vector<T> result;
    for (const auto& pair : storage) {
        result.push_back(pair.second);
    }
    return result;
}
