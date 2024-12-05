cmake_minimum_required(VERSION 3.14...3.29)


project(
    MarsArcheology
    VERSION 0.1.1
    DESCRIPTION "Find life of dead planet"
    LANGUAGES CXX
)

add_subdirectory(src)

add_executable(${PROJECT_NAME} app/main.cpp
        include/mars_archeology/scenes/planet.h
        include/mars_archeology/sprites/map.h
        include/mars_archeology/sprites/vase.h)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE conio befry_engine march)
