cmake_minimum_required (VERSION 3.1)

project (tool LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_C_FLAGS "-O3")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

# follow the top level empty source pattern and add with the subdirectory include files.
add_library(tool STATIC "")
add_executable (tooltest "")

include("src/CMakelists.txt")

# build the tooltest using the test runner and library we just built.
target_link_libraries(tooltest LINK_PUBLIC tool)
