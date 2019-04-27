# version
if(WIN32)
  cmake_minimum_required(VERSION 3.14)
elseif(APPLE)
  cmake_minimum_required(VERSION 3.14)
elseif(UNIX AND NOT UNIX)
  cmake_minimum_required(VERSION 3.14)
endif()
# project name
project(prototype)
# useful variable setting
# std option
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BINARY_DIR build)
# add include file in this project folder
include_directories(include)
# find package in local that is not in std include
if(UNIX)
  find_package(glfw3 3.3 REQUIRED)
  find_package(glm REQUIRED)
elseif(WIN32)
  link_directories(C:/MinGW/lib)
endif()
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
if(UNIX)
  target_link_libraries(prototype glfw glm)
elseif(WIN32)
  target_link_libraries(prototype glfw3dll)
endif()
# run after build
#add_custom_target(run ALL COMMAND "./prototype")
