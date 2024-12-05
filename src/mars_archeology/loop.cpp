#include "loop.h"

#include "scenes/main_menu.h"
#include "scenes/station.h"
#include "scenes/museum.h"
#include "scenes/shop.h"
#include "scenes/planet.h"

#include <unistd.h>
#include <memory>



std::vector<std::unique_ptr<befry::Scene>> march::GameLoop::scenes;
int march::GameLoop::cur_scene = MAIN_MENU;

void march::GameLoop::set_active_scene(const int& scn)
{
    cur_scene = scn;
}

void march::GameLoop::load_scenes()
{
    scenes.push_back(std::make_unique<MainMenu>());
    scenes.push_back(std::make_unique<Station>());
    scenes.push_back(std::make_unique<Museum>());
    scenes.push_back(std::make_unique<Shop>());
    scenes.push_back(std::make_unique<Planet>());
}

void march::GameLoop::game_loop()
{
    scenes[cur_scene]->render();
    scenes[cur_scene]->event();

    usleep(1e6 / befry::Core::get_scene_fps());
    game_loop();
}