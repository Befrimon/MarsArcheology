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

#add_executable(
#        MarsArcheology main.cpp
#
#        ## Game Engine
#        befry_engine/game_object.h
#        befry_engine/scene.h befry_engine/scene.cpp
#
#        # Game Objects (children of game_object.h)
#        befry_engine/game_objects/sprite.h befry_engine/game_objects/sprite.cpp
#
#        # Utility
#        befry_engine/utility/vector2.h befry_engine/utility/vector2.cpp
#)
