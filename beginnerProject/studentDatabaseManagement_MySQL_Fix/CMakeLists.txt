cmake_minimum_required(VERSION 3.20)

project(studentDatabaseManagement_MySQL_Fix)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CONNECTOR_INCLUDE_DIR "D:/CppLibrary/mysql-connector-c++-8.4.0-winx64/include/jdbc")
set(CONNECTOR_LIB_DIR     "D:/CppLibrary/mysql-connector-c++-8.4.0-winx64/lib64/vs14")

include_directories(${CONNECTOR_INCLUDE_DIR})


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

add_definitions(-DCPPCONN_NO_TEST_CODE)


target_link_libraries(studentDatabaseManagement_MySQL_Fix PRIVATE
        "${CONNECTOR_LIB_DIR}/mysqlcppconn8.lib"
        ws2_32.lib
        crypt32.lib
)