cmake_minimum_required(VERSION 3.20)
project(studentDatabaseManagement_MySQL_)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CONNECTOR_INCLUDE_DIR "D:/mysql-connector-c++-9.6.0-winx64/include/jdbc")
set(CONNECTOR_LIB_DIR     "D:/mysql-connector-c++-9.6.0-winx64/lib64/vs14")

include_directories(${CONNECTOR_INCLUDE_DIR})
link_directories(${CONNECTOR_LIB_DIR})

add_executable(inventorySystem_MySQL
        main.cpp
        Product.cpp
        Product.h
        Database.cpp
        Database.h)

target_link_libraries(inventorySystem_MySQL PRIVATE
        "D:/mysql-connector-c++-9.6.0-winx64/lib64/vs14/mysqlcppconn.lib"
        ws2_32.lib
        crypt32.lib
)

add_definitions(-DCPPCONN_PUBLIC_FUNC=)
add_definitions(-DSTATIC_CONCPP)