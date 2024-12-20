#pragma once

#include "core/vector2.h"

#include <string>
#include <string_view>

#ifndef CORE_H
#define CORE_H

namespace befry
{
    template<typename T>
    struct CurMax
    {
        T max_value;
        T value;
    };

    class Core
    {
    protected:
        static std::string texture_path;
        static Vector2 scene_size;
        static int scene_fps;
        static std::string game_dir;

    public:
        static void read_config(std::string_view path);
        static void clear();

        static std::string_view get_texture_path();
        static Vector2 get_scene_size();
        static int get_scene_fps();
        static std::string get_game_dir();
    };
}

#endif
