#pragma once

#include <befry_engine.h>
#include "equip.h"

#ifndef PLAYER_H
#define PLAYER_H

namespace march
{
    enum PlrTools {PICKAXE, SHOVEL, BRUSH};

    class Player
    {
    protected:
        static befry::Vector2 position;
        static std::vector<Tool> tools;

        static int level;
        static int money;
        static befry::CurMax<int> hits;

    public:
        static befry::Vector2 get_position();
        static void move(befry::Vector2 delta);
        static Tool get_tool(PlrTools tool);

        static std::string get_info();
        static std::string get_tool_info();
    };

}

#endif
