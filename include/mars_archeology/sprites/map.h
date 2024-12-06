#pragma once

#include <befry_engine.h>

#ifndef MAP_H
#define MAP_H

namespace march
{
    enum MapMode {GLOBAL, MINI};

    class Map : public befry::Sprite
    {
    protected:
        const std::string tiles[2][2] =
        {
            {"░░", "██"},
            {"##", ""}
        };

        MapMode mode;

        void draw() const override;
    public:

        Map(const std::string& obj_name, const befry::Vector2& pos, const MapMode& m, const int& rect);
        ~Map() override;

        void set_player_pos(befry::Vector2 pos);
    };
}

#endif
