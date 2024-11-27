set(CONIO_H_HEADERS "${PROJECT_SOURCE_DIR}/include/conio.h/")
set(ENGINE_HEADERS "${PROJECT_SOURCE_DIR}/include/befry_engine/")

add_library(befry_engine SHARED
		befry_engine/config.cpp
        ## Core
        befry_engine/core/scene.cpp
        befry_engine/core/vector2.cpp
		befry_engine/core/input.cpp
        ## GameObjects
        befry_engine/game_objects/sprite.cpp
        ## UI Objects
        befry_engine/user_interface/canvas_item.cpp
        befry_engine/user_interface/label.cpp
        befry_engine/user_interface/button.cpp
		befry_engine/user_interface/button_group.cpp
		befry_engine/user_interface/separator.cpp
)
target_include_directories(befry_engine PUBLIC ${ENGINE_HEADERS})

add_library(conio.h SHARED conio.cpp)
target_include_directories(conio.h PUBLIC ${CONIO_H_HEADERS})

target_link_libraries(befry_engine PRIVATE conio.h)
