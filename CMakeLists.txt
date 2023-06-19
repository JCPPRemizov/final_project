cmake_minimum_required(VERSION 3.25)
project(final_project)

set(CMAKE_CXX_STANDARD 23)


file(GLOB_RECURSE SOURCES Models/*.h Pages/*.h Functions/*.cpp Functions/*.h libs/*.hpp)

add_executable(final_project main.cpp ${SOURCES} Functions/EmployeeFunctions.h)

target_include_directories(final_project PRIVATE Models Pages Functions libs)
