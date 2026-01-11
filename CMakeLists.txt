cmake_minimum_required(VERSION 3.30)
project(modern_cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_subdirectory(external/googletest)

enable_testing()

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Compiler Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
    add_compile_options(-stdlib=libc++)
    add_link_options(-stdlib=libc++)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Compiler GCC")
    add_compile_options(-Wall -Wextra -Wpedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Compiler MSVC")
    add_compile_options(/W4 /WX /std:c++23)
endif()

add_executable(demangling src/05_demangling.cpp)
add_executable(replace src/08_replace.cpp)
add_executable(optional src/10_optional.cpp)
add_executable(async src/11_async.cpp)
add_executable(templates src/14_templates.cpp src/stackinst.cpp)
add_executable(memory_allocation src/15_memory_allocation.cpp)
add_executable(constructors src/17_constructors.cpp)
add_executable(ostream src/17_ostream.cpp)
add_executable(typesafe_ids src/20_typesafe_ids.cpp)
add_executable(calling_convetions src/21_calling_conventions.cpp)

# TDD

include(GoogleTest)

add_executable(google_test_examples tests/00_google_test.cpp)
target_link_libraries(google_test_examples gtest_main)
gtest_discover_tests(google_test_examples)

add_executable(std_print tests/01_test_std_print.cpp)
target_link_libraries(std_print gtest_main)
gtest_discover_tests(std_print)

add_executable(auto_keyword tests/02_test_auto_keyword.cpp)
target_link_libraries(auto_keyword gtest_main)
gtest_discover_tests(auto_keyword)

add_executable(test_iota tests/03_test_std_iota.cpp)
target_link_libraries(test_iota gtest_main)
gtest_discover_tests(test_iota)

add_executable(unique_pointers tests/08_0_unique_pointers.cpp)
target_link_libraries(unique_pointers gtest_main)
gtest_discover_tests(unique_pointers)

add_executable(test_smart_pointers tests/08_1_unique_pointer_own_impl.cpp)
target_link_libraries(test_smart_pointers gtest_main)
gtest_discover_tests(test_smart_pointers)

add_executable(test_std_span tests/09_test_std_span.cpp)
target_link_libraries(test_std_span gtest_main)
gtest_discover_tests(test_std_span)

add_executable(test_array tests/02_test_std_array.cpp)
target_link_libraries(test_array gtest_main)
gtest_discover_tests(test_array)

add_executable(test_vector tests/04_test_vector.cpp)
target_link_libraries(test_vector gtest_main)
gtest_discover_tests(test_vector)

add_executable(test_lambdas tests/05_test_lambdas.cpp)
target_link_libraries(test_lambdas gtest_main)
gtest_discover_tests(test_lambdas)

add_executable(test_ranges tests/07_test_ranges.cpp)
target_link_libraries(test_ranges gtest_main)
gtest_discover_tests(test_ranges)

add_executable(test_ctors tests/17_test_rule_of_three.cpp)
target_link_libraries(test_ctors gtest_main)
gtest_discover_tests(test_ctors)

add_executable(test_chrono tests/18_test_chrono.cpp)
target_link_libraries(test_chrono gtest_main)
gtest_discover_tests(test_chrono)

