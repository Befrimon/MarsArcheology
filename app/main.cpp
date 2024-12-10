#include <core.h>
#include <loop.h>
#include <expeditions/wasteland.h>
#include <scenes/main_menu.h>
#include <scenes/planet.h>

namespace march
{
    class Planet;
}

int main()
{
    conio::console::hideCursor();
    befry::Core::read_config("/config");
    march::GameLoop::load_scenes();

    std::static_pointer_cast<march::Planet>(march::GameLoop::get_scene(march::PLANET))
        ->start_expedition(march::WASTELAND);

    march::GameLoop::set_active_scene(march::PLANET);

    march::GameLoop::game_loop();

    return 0;
}
