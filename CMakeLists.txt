cmake_minimum_required(VERSION 3.30)
project(Proiect_comun)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(controller)
add_subdirectory(domain)
add_subdirectory(repository)
add_subdirectory(ui)
add_subdirectory(test)

add_executable(Proiect_comun main.cpp
        services/UserService.cpp
        ui/OrderManagementUI.cpp
        ui/OrderManagementUI.h)

target_sources(Proiect_comun PRIVATE
        controller/ClientManagementController.cpp
        controller/OrderController.cpp
        controller/ProductController.cpp
        controller/UserManagementController.cpp
)

target_sources(Proiect_comun PRIVATE
        domain/Customer.cpp
        domain/Employee.cpp
        domain/Order.cpp
        domain/Product.cpp
        domain/User.cpp
        domain/Validations/CustomerValidator.cpp
        domain/Validations/EmployeeValidator.cpp
        domain/Validations/OrderValidator.cpp
        domain/Validations/ProductValidator.cpp
        domain/Validations/UserValidator.cpp
)

target_sources(Proiect_comun PRIVATE
        repository/InMemoryRepository.h
        repository/UserRepository.cpp
        repository/DataSeeder.cpp
)

target_sources(Proiect_comun PRIVATE
        ui/ClientManagementUI.cpp
        ui/UI.cpp
        ui/UserManagementUI.cpp
        ui/ProductManagementUI.cpp
)

target_include_directories(Proiect_comun PRIVATE
        controller
        domain
        repository
        ui
        test
)