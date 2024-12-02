#pragma once

#include <vector>

#include <befry_engine.h>
#include <unistd.h>

#ifndef LOOP_H
#define LOOP_H

namespace march
{
    class GameLoop
    {
    protected:
        static std::vector<befry::Scene*> scenes;
        static int cur_scene;

    public:
        static void load_scene(befry::Scene* scn);
        static void game_loop();
    };
}

#endif
