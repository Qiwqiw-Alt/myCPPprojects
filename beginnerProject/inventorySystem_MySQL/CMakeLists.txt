cmake_minimum_required(VERSION 4.1)
project(inventorySystem_MySQL)

set(CMAKE_CXX_STANDARD 14)

add_executable(inventorySystem_MySQL
        main.cpp
        Product.cpp
        Product.h
        Database.cpp
        Database.h)
