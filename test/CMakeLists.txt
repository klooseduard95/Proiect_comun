# Enable testing in this folder
enable_testing()

# Download and link GoogleTest
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

# Prevent GoogleTest from overriding compiler/linker options
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Create test executable
add_executable(ProductTest ProductTest.cpp)

# Link GoogleTest and your domain code (adjust path to your domain folder)
target_link_libraries(ProductTest
        gtest_main
)

target_include_directories(ProductTest PRIVATE
        ../domain
        ../domain/Validations
)

# Add your domain sources here if needed (if code is header-only, no need)
target_sources(ProductTest PRIVATE
        ../domain/Product.cpp
        ../domain/Validations/ProductValidator.cpp
)

# Register the test to CTest
include(GoogleTest)
gtest_discover_tests(ProductTest)

# --- Customer Test ---
add_executable(CustomerTest CustomerTest.cpp)

target_link_libraries(CustomerTest
        gtest_main
)

target_include_directories(CustomerTest PRIVATE
        ../domain
        ../domain/Validations
)

target_sources(CustomerTest PRIVATE
        ../domain/Customer.cpp
        ../domain/User.cpp
)

gtest_discover_tests(CustomerTest)


# --- Employee Test ---
add_executable(EmployeeTest EmployeeTest.cpp)

target_link_libraries(EmployeeTest
        gtest_main
)

target_include_directories(EmployeeTest PRIVATE
        ../domain
        ../domain/Validations
)

target_sources(EmployeeTest PRIVATE
        ../domain/Employee.cpp
        ../domain/User.cpp
)

gtest_discover_tests(EmployeeTest)
