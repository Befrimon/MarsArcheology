#include <core.h>
#include <loop.h>
#include <scenes/main_menu.h>

#include <sprites/vase.h>

int main()
{
    conio::console::hideCursor();
    befry::Core::read_config("config");
    march::GameLoop::load_scenes();
    march::GameLoop::game_loop();

    return 0;
}
