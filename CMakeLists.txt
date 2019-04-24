cmake_minimum_required(VERSION 3.14)
project(prototype)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2 -Wall")

include_directories(include)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

add_custom_target(run ALL COMMAND "./prototype")

add_executable(prototype
        src/glad.c
        src/main.cpp)

# link not all included libralies but ones that you really included
target_link_libraries(prototype glfw glm)
