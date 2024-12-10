#pragma once

#include <vector>
#include <memory>

#include <befry_engine.h>

#ifndef LOOP_H
#define LOOP_H

namespace march
{
    enum SCENES {MAIN_MENU, STATION, MUSEUM, SHOP, PLANET};

    class GameLoop
    {
    protected:
        static std::vector<std::shared_ptr<befry::Scene>> scenes;
        static int cur_scene;

    public:
        static void set_active_scene(const int& scn);
        static std::shared_ptr<befry::Scene> get_scene(const int& scn);
        static void load_scenes();
        static void game_loop();
    };
}

#endif
