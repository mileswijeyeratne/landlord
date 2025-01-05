cmake_minimum_required(VERSION 3.15)
project(MyProject)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(common)
add_subdirectory(client)
add_subdirectory(server)
