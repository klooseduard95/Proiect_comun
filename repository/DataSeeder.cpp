#include "DataSeeder.h"

void DataSeeder::seedUsers(UserRepository& userRepository) {
    userRepository.add(User("alice@example.com", "alicepass", "customer"));
    userRepository.add(User("bob@example.com", "bobpass", "employee"));
    userRepository.add(User("admin@example.com", "adminpass", "customer"));
}

void DataSeeder::seedProducts(ProductController& productController) {
    productController.createProduct("P001", "Laptop", 2999.99, 10);
    productController.createProduct("P002", "Telefon", 1599.99, 5);
    productController.createProduct("P003", "Mouse", 99.99, 15);
}

void DataSeeder::seedCustomers(InMemoryRepository<Customer>& customerRepo) {
    customerRepo.add(Customer("alice@example.com", "alicepass", "Alice", "InWonderland", "Strada Lalelelor 10"));
    customerRepo.add(Customer("bob@example.com", "bobpass", "Bob", "Dob", "Strada Florilor 5"));
}

void DataSeeder::seedOrders(OrderController& orderController, const User& user, InMemoryRepository<Customer>& customerRepo) {
    Customer customer = customerRepo.getById(user.getId());

    Employee employee("emp001", "pass123", "Radu", "Mihai", "Manager", "1985-01-01", 3000);

    std::vector<std::pair<Product, int>> produse = {
        { Product("P001", "Laptop", 3000.0, 5), 1 },
        { Product("P003", "Mouse", 50.0, 10), 2 }
    };

    double totalPrice = 0.0;
    for (const auto& p : produse) {
        totalPrice += p.first.getPrice() * p.second;
    }

    Order order("ord001", "2025-05-20", OrderStatus::Reservation, produse, customer, employee, totalPrice);

    orderController.createReservation(user, order);

    orderController.confirmOrder(order.getId());
    orderController.completeOrder(order.getId());
}




