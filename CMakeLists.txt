cmake_minimum_required(VERSION 3.14...3.29)
set(ALLOW_DUPLICATE_CUSTOM_TARGETS TRUE)

project(
        MarsArcheology
        VERSION 0.1
        DESCRIPTION "Find life of dead planet"
        LANGUAGES CXX
)

add_executable(
        MarsArcheology main.cpp

        ## Game Engine
        game_engine/game_object.h
        game_engine/scene.h game_engine/scene.cpp

        # Game Objects (children of game_object.h)
        game_engine/game_objects/sprite.h game_engine/game_objects/sprite.cpp

        # Utility
        game_engine/utility/vector2.h
        game_engine/utility/colors.h
        game_engine/utility/key_listener.h
)
