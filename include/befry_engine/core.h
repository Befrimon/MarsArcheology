#pragma once

#include "core/vector2.h"

#include <string>
#include <string_view>

#ifndef CORE_H
#define CORE_H

namespace befry
{
    class Core
    {
    protected:
        static std::string texture_path;
        static Vector2 scene_size;
        static int scene_fps;

    public:
        static void read_config(std::string_view path);
        static void clear();

        static std::string_view get_texture_path();
        static Vector2 get_scene_size();
        static int get_scene_fps();
    };
}

#endif
