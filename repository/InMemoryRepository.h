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

/**
 * @brief Clasa template care implementeaza un repository in memorie folosind un unordered_map.
 *
 * @tparam T Tipul entitatii. T trebuie sa aiba o metoda getId() care returneaza un identificator unic de tip string.
 */
template <typename T>
class InMemoryRepository : public IRepository<T> {
private:
    /// Container pentru stocare, mapand ID-urile entitatilor la entitatile respective.
    std::unordered_map<std::string, T> storage;

public:
    /**
     * @brief Adauga o entitate noua in repository.
     * @param entity Entitatea de adaugat.
     * @throws std::runtime_error daca exista deja o entitate cu acelasi ID.
     */
    void add(const T& entity) override {
        auto id = entity.getId();
        if (storage.find(id) != storage.end()) {
            throw std::runtime_error("Entity with ID already exists.");
        }
        storage[id] = entity;
    }

    /**
     * @brief Actualizeaza o entitate existenta.
     * @param entity Entitatea care va fi actualizata.
     * @throws std::runtime_error daca entitatea nu este gasita.
     */
    void update(const T& entity) override {
        auto id = entity.getId();
        if (storage.find(id) == storage.end()) {
            throw std::runtime_error("Entity not found.");
        }
        storage[id] = entity;
    }

    /**
     * @brief Sterge o entitate dupa ID.
     * @param id ID-ul entitatii de sters.
     * @throws std::runtime_error daca entitatea nu este gasita.
     */
    void remove(const std::string& id) override {
        if (storage.erase(id) == 0) {
            throw std::runtime_error("Entity not found for deletion.");
        }
    }

    /**
     * @brief Returneaza o entitate dupa ID.
     * @param id ID-ul entitatii cautate.
     * @return Entitatea gasita.
     * @throws std::runtime_error daca entitatea nu este gasita.
     */
    T getById(const std::string& id) const override {
        auto it = storage.find(id);
        if (it == storage.end()) {
            throw std::runtime_error("Entity not found.");
        }
        return it->second;
    }

    /**
     * @brief Returneaza toate entitatile stocate.
     * @return Vector cu toate entitatile din repository.
     */
    std::vector<T> getAll() const override {
        std::vector<T> result;
        for (const auto& pair : storage) {
            result.push_back(pair.second);
        }
        return result;
    }
};

#endif // INMEMORYREPOSITORY_H


