# Fetch GTest
enable_testing()

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# --- ProductTest ---
add_executable(ProductTest ProductTest.cpp
        ../domain/Product.cpp
        ../domain/Validations/ProductValidator.cpp
)

target_include_directories(ProductTest PRIVATE
        ../domain
        ../domain/Validations
)

target_link_libraries(ProductTest
        gtest
        gtest_main
)

gtest_discover_tests(ProductTest)

# --- CustomerTest ---
add_executable(CustomerTest CustomerTest.cpp
        ../domain/Customer.cpp
        ../domain/User.cpp
)

target_include_directories(CustomerTest PRIVATE
        ../domain
        ../domain/Validations
)

target_link_libraries(CustomerTest
        gtest
        gtest_main
)

gtest_discover_tests(CustomerTest)

# --- EmployeeTest ---
add_executable(EmployeeTest EmployeeTest.cpp
        ../domain/Employee.cpp
        ../domain/User.cpp
)

target_include_directories(EmployeeTest PRIVATE
        ../domain
        ../domain/Validations
)

target_link_libraries(EmployeeTest
        gtest
        gtest_main
)

gtest_discover_tests(EmployeeTest)

# --- UserTest ---
add_executable(UserTest UserTest.cpp
                ../domain/User.cpp
)

target_include_directories(UserTest PRIVATE
                            ../domain
                            ../domain/Validations
)

target_link_libraries(UserTest
        gtest
        gtest_main
)

gtest_discover_tests(UserTest)