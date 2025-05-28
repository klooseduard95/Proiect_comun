#include "repository/UserRepository.h"
#include "repository/InMemoryRepository.h"
#include "services//UserService.h"
#include "controller/UserManagementController.h"
#include "controller/ProductController.h"
#include "controller/OrderController.h"
#include "controller/ClientManagementController.h"
#include "ui/UserManagementUI.h"
#include "ui/ProductManagementUI.h"
#include "ui/OrderManagementUI.h"
#include "ui/ClientManagementUI.h"
#include "ui/UI.h"
#include <iostream>

#include "DataSeeder.h"

int main() {
    // creeaza repository-urile
    UserRepository userRepo;
    InMemoryRepository<Product> productRepo;
    InMemoryRepository<Order> orderRepo;
    InMemoryRepository<Customer> customerRepo;

    // creeaza controller-ele
    UserService userService(userRepo);
    UserManagementController userController(userService);
    ProductController productController(&productRepo);
    OrderController orderController(orderRepo);
    CustomerController customerController(&customerRepo, &orderController);

    // Populeaza datele initiale
    DataSeeder::seedUsers(userRepo);
    DataSeeder::seedCustomers(customerRepo);
    DataSeeder::seedProducts(productController);

    User user;
    try {
        user = userRepo.getById("alice@example.com");
    } catch (const std::exception& e) {
        std::cerr << "Eroare la preluarea userului: " << e.what() << std::endl;
        return 1;
    }
    DataSeeder::seedOrders(orderController, user, customerRepo);

    // creeaza UI-uri auxiliare
    CustomerUI customerUI(customerController);
    ProductUI productUI(productController);
    OrderManagementUI orderUI(orderController);

    // creeaza UI principal
    UserManagementUI ui(userController, productController, orderController, customerController, customerUI, productUI, orderUI);

    UI mainUI(ui);
    mainUI.run();

    return 0;
}

