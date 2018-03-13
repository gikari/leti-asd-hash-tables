cmake_minimum_required(VERSION 2.6)
project(lab_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lab_3 main.cpp Hash_Table.cpp Set.cpp Set.h)

install(TARGETS lab_3 RUNTIME DESTINATION bin)
