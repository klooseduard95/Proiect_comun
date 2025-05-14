#include <iostream>
#include "controller/ProductController.h"
#include "repository/InMemoryRepository.h"
#include "domain/Product.h"

int main() {
    InMemoryRepository<Product> productRepo;


    ProductController productController(&productRepo);


    productController.createProduct("P001", "Laptop", 2999.99, 10);
    productController.createProduct("P002", "Telefon", 1599.99, 5);


    productController.listAvailableProducts();

    return 0;
}
