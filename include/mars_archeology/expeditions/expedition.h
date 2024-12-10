#pragma once

#include <PerlinNoise.hpp>
#include <befry_engine.h>
#include <string>

#ifndef EXPEDITION_H
#define EXPEDITION_H

namespace march
{
    struct Terrain
    {
        int sands;
        int dirt;
        int ice_dirt;
        int ice;
        int rock;
    };

    class Expedition
    {
    protected:
        const int size = 15;
        std::vector<std::vector<double>> cur_tile;

        std::string name;
        Terrain terr_type{};
        int temp;

        virtual void effect() = 0;

    public:
        Expedition();
        virtual ~Expedition() = default;

        virtual void explore(befry::Vector2 coord);
        virtual std::string get_tile(befry::Vector2 coord);
    };
}

#endif
