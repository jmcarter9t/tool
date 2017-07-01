cmake_minimum_required (VERSION 3.1)

project (tool LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_C_FLAGS "-O3")

include_directories("./include")
set(TOOL_SRC "src/tool.cpp"
             "src/test.cpp"
   )

add_executable (tool ${TOOL_SRC})
