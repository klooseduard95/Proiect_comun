cmake_minimum_required(VERSION 3.30)
project(Proiect_comun)
set(CMAKE_CXX_STANDARD 20)
add_executable(Proiect_comun main.cpp
        controller/ClientManagementController.cpp
        controller/ProductController.cpp
        controller/UserManagementController.cpp
        domain/Customer.cpp
        domain/Employee.cpp
        domain/Order.cpp
        domain/Product.cpp
        domain/User.cpp
        ui/ClientManagementUI.cpp
        ui/UI.cpp
        ui/UserManagementUI.cpp
        domain/Validations/CustomerValidator.cpp
        domain/Validations/EmployeeValidator.cpp
        domain/Validations/UserValidator.cpp)