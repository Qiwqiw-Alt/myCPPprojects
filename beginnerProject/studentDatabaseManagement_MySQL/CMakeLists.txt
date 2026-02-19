cmake_minimum_required(VERSION 3.20)
project(studentDatabaseManagement_MySQL_)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CONNECTOR_INCLUDE_DIR "D:/mysql-connector-c++-9.6.0-winx64/include")
set(CONNECTOR_LIB_DIR "D:/mysql-connector-c++-9.6.0-winx64/lib64")


include_directories(${CONNECTOR_INCLUDE_DIR})
link_directories(${CONNECTOR_LIB_DIR})

add_executable(studentDatabaseManagement_MySQL_
        main.cpp
        Student.cpp
        Student.h
        Database.cpp
        Database.h)
target_link_libraries(${PROJECT_NAME} mysqlcppconn)