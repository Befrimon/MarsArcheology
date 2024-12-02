#include "loop.h"

std::vector<befry::Scene*> march::GameLoop::scenes;
int march::GameLoop::cur_scene = 0;

void march::GameLoop::load_scene(befry::Scene* scn)
{
    scenes.push_back(scn);
}


void march::GameLoop::game_loop()
{
    scenes[cur_scene]->render();
    scenes[cur_scene]->event();

    usleep(1e6 / befry::Core::get_scene_fps());
    game_loop();
}