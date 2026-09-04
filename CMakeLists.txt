cmake_minimum_required(VERSION 3.24)

project(int2025_t LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib)
add_subdirectory(bin)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
