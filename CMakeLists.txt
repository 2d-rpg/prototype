# version
cmake_minimum_required(VERSION 3.14)
# project name
project(prototype)
# useful variable setting
# std option
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BINARY_DIR build)
# add include file in this project folder
include_directories(include)
# find package in local that is not in std include
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)
# create executable file
add_executable(prototype
  src/renderer/map.cpp
  src/shader/shader.cpp
  src/texture/texture_2D.cpp
  src/texture/texture_manager.cpp
  src/glad.c
  src/stb_image.cpp
  src/utils.cpp
  src/main.cpp)
# compile option
target_compile_options(prototype PUBLIC -O2 -Wall -Wextra)
# link libraries
target_link_libraries(prototype glfw glm)
# run after build
#add_custom_target(run ALL COMMAND "./prototype")
