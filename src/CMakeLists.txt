set(ENGINE_HEADERS "${PROJECT_SOURCE_DIR}/include/befry_engine/")

add_library(
        befry_engine SHARED
        ## .cpp files
        befry_engine/scene.cpp befry_engine/game_objects/sprite.cpp befry_engine/utility/vector2.cpp
)
target_include_directories(befry_engine PUBLIC ${ENGINE_HEADERS})