#include <iostream>
#include <UserManagementController.h>
#include <UserManagementUI.h>
#include <UserRepository.h>

#include "controller/ProductController.h"
#include "repository/InMemoryRepository.h"
#include "domain/Product.h"

int main() {
    InMemoryRepository<Product> productRepo;


    ProductController productController(&productRepo);


    productController.createProduct("P001", "Laptop", 2999.99, 10);
    productController.createProduct("P002", "Telefon", 1599.99, 5);


    productController.listAvailableProducts();

    UserRepository userRepository;
    userRepository.add(User("alice@example.com", "alicepass", "customer"));
    userRepository.add(User("bob@example.com", "bobpass", "employee"));
    userRepository.add(User("admin@example.com", "adminpass", "customer"));
    UserService userService(userRepository);
    UserManagementController userController(userService);
    UserManagementUI userUI(userController);


    userUI.startLoginFlow();

    return 0;
}
