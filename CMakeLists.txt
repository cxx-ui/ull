project(ull)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 COMPONENTS "Widgets" "DBus")

add_library(ull INTERFACE)
target_include_directories(ull INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(ull INTERFACE Qt6::Widgets)

add_subdirectory(examples)
