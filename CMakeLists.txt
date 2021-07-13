cmake_minimum_required(VERSION 3.19)
project(HostsFileFixer)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(HostsFileFixer main.cpp)

