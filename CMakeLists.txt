cmake_minimum_required(VERSION 3.14...3.29)
set(ALLOW_DUPLICATE_CUSTOM_TARGETS TRUE)

project(
        MarsArcheology
        VERSION 0.1
        DESCRIPTION "Find life of dead planet"
        LANGUAGES CXX
)

# My libs
add_subdirectory(src)

# Executable
add_subdirectory(apps)
