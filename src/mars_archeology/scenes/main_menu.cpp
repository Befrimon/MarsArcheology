#include <befry_engine.h>

#include "scenes/main_menu.h"
#include "loop.h"

march::MainMenu::MainMenu()
{
    children.push_back(new befry::Sprite("Logo", befry::Vector2{2, 2}, "logo"));
    children.push_back(new befry::Sprite("Description", befry::Vector2{10, 10}, "sublogo"));

    GameLoop::load_scene(this);
}
march::MainMenu::~MainMenu() = default;

befry::GameObject& march::MainMenu::get_child(std::string obj_name) const
{
}


void march::MainMenu::render()
{
    Scene::render();

    for (befry::GameObject* obj : children)
        obj->update();
}

void march::MainMenu::event()
{
    if (conio::console::kbhit()) switch (befry::Input::get_key())
    {
        case KEY_Q:
            exit(0);
        case KEY_H:
            break;
        case KEY_SPACE:
            break;
        case KEY_UP:
            break;
        case KEY_DOWN:
            break;
        default:
            break;
    }
}

