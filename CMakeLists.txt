# pbc
# CMakeLists.txt

# CMake settings -------------------------------------------------------

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Project --------------------------------------------------------------

# Defaults
project(pbc VERSION 0.0.0)

# Compiler
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CMake helpers
if(NOT COMMAND add_gtest)
  include(${PROJECT_SOURCE_DIR}/modules/cmake-helpers/Helpers.cmake)
endif()

# Options --------------------------------------------------------------

option(WITH_pbc_TESTS "Build pbc tests." OFF)

# Dependencies ---------------------------------------------------------

add_subdirectory(${PROJECT_SOURCE_DIR}/modules/cli11)

if(WITH_pbc_TESTS AND NOT TARGET gtest)
  if(MSVC)
    force_bool(gtest_force_shared_crt ON)
  endif()

  add_subdirectory(${PROJECT_SOURCE_DIR}/modules/gtest)
endif()

# Adding globally because almost everything will use asio.
include_directories(${PROJECT_SOURCE_DIR}/modules/asio/asio/include)
add_compile_options("-DASIO_STANDALONE")

# Source ---------------------------------------------------------------

# CMake/code integration
configure_file(
  ${PROJECT_SOURCE_DIR}/include/pbc/Config.hh.in
  ${PROJECT_BINARY_DIR}/include/pbc/Config.hh
)

# Include
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR}/include # Needed for configured file
)

add_subdirectory(${PROJECT_SOURCE_DIR}/source)

# Tests ----------------------------------------------------------------

if(WITH_pbc_TESTS)
  enable_testing()
  add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()
