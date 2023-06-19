cmake_minimum_required(VERSION 3.5)
project(planners)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(
  include
)

set(executable_name planner)
# set(library_name planner_libs)

# add_library(
#   ${library_name}
# )

add_executable(${executable_name}
  main.cpp
)
# target_link_libraries(${executable_name} ${library_name})