cmake_minimum_required(VERSION 3.20)
project(calculator_GUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(wxWidgets_ROOT_DIR "D:/CppLibrary/wxWidgets")
set(wxWidgets_LIB_DIR "D:/CppLibrary/wxWidgets/lib/gcc_lib")

set(wxWidgets_USE_STATIC ON)
set(wxWidgets_USE_UNICODE ON)
set(wxWidgets_USE_REL_AND_DBG ON)
#set(wxWidgets_CONFIGURATION mswu)

find_package(wxWidgets REQUIRED COMPONENT core base)
if(NOT wxWidgets_FOUND)
    message(FATAL_ERROR "wxWidgets not found! Check the paths wxWidgets_ROOT_DIR and wxWidgets_LIB_DIR")
endif()
include(${wxWidgets_USE_FILE})

add_executable(calculator_GUI
        main.cpp
        Calculator.cpp
        Calculator.h)

target_link_libraries(calculator_GUI PRIVATE ${wxWidgets_LIBRARIES})

if(MINGW)
    target_link_options(calculator_GUI PRIVATE
            -static
            -static-libgcc
            -static-libstdc++
    )
endif()

set_target_properties(calculator_GUI PROPERTIES
        OUTPUT_NAME "Calculator"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)