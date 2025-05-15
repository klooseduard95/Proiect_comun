//
// Created by adeli on 5/15/2025.
//

#ifndef PRODUCTVALIDATOR_H
#define PRODUCTVALIDATOR_H

#include "../domain/Product.h"
#include <stdexcept>
#include <regex>

class ProductValidator {
public:
    static void validateForCreate(const Product& product);
    static void validateForUpdate(const Product& product);
private:
    static void validateCommon(const Product& product);
};



#endif //PRODUCTVALIDATOR_H
