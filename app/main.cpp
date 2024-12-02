#include <core.h>
#include <loop.h>
#include <scenes/main_menu.h>

int main()
{
    befry::Core::read_config("config");
    march::MainMenu start = march::MainMenu();
    march::GameLoop::game_loop();

    return 0;
}
