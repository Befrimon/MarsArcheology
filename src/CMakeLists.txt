set(HEADERS "${PROJECT_SOURCE_DIR}/include/")

## Create conio.h lib
add_library(conio SHARED conio/conio.cpp)
target_include_directories(conio PUBLIC ${HEADERS}/conio/)

## Create befry_engin.h lib
add_library(befry_engine SHARED
    ## Core
    befry_engine/core.cpp
    befry_engine/core/input.cpp
    befry_engine/core/vector2.cpp
    befry_engine/core/scene.cpp

    ## Game Objects
    befry_engine/game_objects/sprite.cpp

    ## User Interface
    befry_engine/user_interface/button.cpp
    befry_engine/user_interface/button_group.cpp
    befry_engine/user_interface/canvas_item.cpp
    befry_engine/user_interface/label.cpp
    befry_engine/user_interface/separator.cpp
)
target_include_directories(befry_engine PUBLIC ${HEADERS}/befry_engine/)
target_link_libraries(befry_engine PRIVATE conio)

## Add march executable
add_library(march STATIC
    mars_archeology/loop.cpp
    mars_archeology/scenes/main_menu.cpp
)
target_include_directories(march PUBLIC ${HEADERS}/mars_archeology/)
target_link_libraries(march PRIVATE befry_engine)
