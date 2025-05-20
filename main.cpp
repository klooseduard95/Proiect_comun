#include <iostream>
#include <Order.h>
#include <UserManagementController.h>
#include <UserManagementUI.h>
#include <ProductManagementUI.h>
#include <UserRepository.h>

#include "controller/ProductController.h"
#include "controller/OrderController.h"
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

    InMemoryRepository<Order> orderRepo;
    OrderController orderController(orderRepo);

    Customer customer("ion@example.com", "ionpass", "Ion", "Popescu", "Strada Exemplu 10");
    Employee employee("emp001", "pass123", "Andrei", "Ionescu", "Manager", "1985-01-01", 3000);

    std::vector<std::pair<Product,int>> produse = {
        { Product("prod001", "Laptop", 3000.0, 5), 1 },
        { Product("prod002", "Mouse", 50.0, 10), 2 }
    };

    Order order1("ord001", "2025-05-20", OrderStatus::Reservation, produse, customer, employee, 3100.0);
    orderController.createReservation(order1);
    std::cout << "Rezervare ord001 creata.\n";

    orderController.confirmOrder("ord001");
    std::cout << "Comanda ord001 confirmata.\n";

    orderController.completeOrder("ord001");
    std::cout << "Comanda ord001 finalizata.\n";

    double totalMai = orderController.getTotalSumForPeriod("2025", "05");
    std::cout << "Suma totala comenzi mai 2025: " << totalMai << "\n";

    auto comenziConfirmate = orderController.getOrdersByStatus(OrderStatus::Confirmed);
    std::cout << "Numar comenzi confirmate: " << comenziConfirmate.size() << "\n";

    auto comenziFinalizate = orderController.getOrdersByStatus(OrderStatus::Completed);
    std::cout << "Numar comenzi finalizate: " << comenziFinalizate.size() << "\n";

    ProductUI productUI(productController);
    productUI.showMenu();


    userUI.startLoginFlow();

    return 0;
}
