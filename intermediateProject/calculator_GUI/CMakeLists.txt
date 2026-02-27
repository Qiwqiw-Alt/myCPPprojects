cmake_minimum_required(VERSION 3.20)
project(calculator_GUI)

set(CMAKE_CXX_STANDARD 17)
set(wxWidgets_ROOT_DIR "D:/CppLibrary/wxWidgets")
set(wxWidgets_LIB_DIR "D:/CppLibrary/wxWidgets/lib/gcc_lib")

set(wxWidgets_USE_REL_AND_DBG ON)
set(wxWidgets_CONFIGURATION mswu)

find_package(wxWidgets REQUIRED COMPONENTS mono)
include(${wxWidgets_USE_FILE})

add_executable(calculator_GUI
        main.cpp
        calculator.cpp)

target_link_libraries(calculator_GUI ${wxWidgets_LIBRARIES})