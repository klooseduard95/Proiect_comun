#pragma once

#include "UserManagementController.h"
#include "../services/UserService.h"
#include "../controller/ProductController.h"
#include "../controller/ClientManagementController.h"
#include "../controller/OrderController.h"
#include "../domain/Customer.h"
#include "../domain/Employee.h"

class DataSeeder {
public:
    static void seedUsers(UserRepository& userRepository);
    static void seedProducts(ProductController& productController);
    static void seedCustomers(InMemoryRepository<Customer>& customerRepo);
    static void seedOrders(OrderController& orderController, const User& user, InMemoryRepository<Customer>& customerRepo);
};
