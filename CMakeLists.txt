cmake_minimum_required(VERSION 3.14)
project(cephes)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Coverage
include(${CMAKE_SOURCE_DIR}/tests/Coverage.cmake)

# libcephes compilation and installation is in its own subdirectory
add_subdirectory(cephes)

# Tests
enable_testing()
add_subdirectory(tests)
