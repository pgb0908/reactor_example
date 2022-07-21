cmake_minimum_required(VERSION 3.14)

project(
        Reactor-pattern
        LANGUAGES CXX
        VERSION "1.0.0"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(reactor main.cpp reactor.cpp)
