cmake_minimum_required(VERSION 3.20)  # Lebih baru dari 4.1 biar aman di CLion terbaru

project(studentDatabaseManagement_MySQL_Fix)

set(CMAKE_CXX_STANDARD 20)  # Naikkan ke 17 atau 20 kalau kode kamu support (lebih modern)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path ke Connector/C++ 8.4 (sesuaikan kalau folder kamu beda)
set(CONNECTOR_INCLUDE_DIR "D:/mysql-connector-c++-8.4.0-winx64/include/jdbc")
set(CONNECTOR_LIB_DIR     "D:/mysql-connector-c++-8.4.0-winx64/lib64/vs14")  # vs14 biasanya untuk MSVC 2015+, match VS2022

include_directories(${CONNECTOR_INCLUDE_DIR})

# Tambah UTF-8 support aman untuk MSVC
if(MSVC)
    add_compile_options(/utf-8)
endif()

add_executable(studentDatabaseManagement_MySQL_Fix
        Database.cpp
        Database.h
        main.cpp
        Student.cpp
        Student.h
)

add_definitions(-DCPPCONN_NO_TEST_CODE)  # kalau connector support macro ini

# Link dynamic library (mysqlcppconn8.lib) + deps Windows
target_link_libraries(studentDatabaseManagement_MySQL_Fix PRIVATE
        "${CONNECTOR_LIB_DIR}/mysqlcppconn8.lib"  # dynamic lib (bukan static dulu)
        ws2_32.lib
        crypt32.lib
)