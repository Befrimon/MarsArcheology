set(ENGINE_HEADERS "${PROJECT_SOURCE_DIR}/include/befry_engine/")

add_library(
        befry_engine SHARED
        ## Core
        befry_engine/scene.cpp befry_engine/utility/vector2.cpp
        ## GameObjects
        befry_engine/game_objects/sprite.cpp
        ## UI Objects
        befry_engine/user_interface/button.cpp
)
target_include_directories(befry_engine PUBLIC ${ENGINE_HEADERS})