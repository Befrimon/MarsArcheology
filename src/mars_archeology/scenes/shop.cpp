#include "scenes/shop.h"
#include "loop.h"

#include <memory>

march::Shop::Shop()
{
    children.push_back(std::make_shared<befry::Sprite>("Background", befry::Vector2{1, 1}, "shop"));
    children.push_back(std::make_shared<befry::Label>("ControlsInfo", befry::Vector2{1, 40}, befry::Vector2{140, 1}, " Back to hall "));
}
march::Shop::~Shop() = default;

int march::Shop::render()
{
    if (Scene::render() == -1)
        return -1;

    for (std::shared_ptr<befry::GameObject> obj : children)
        obj->update();

    return 0;
}

void march::Shop::event()
{
    if (conio::console::kbhit()) switch(befry::Input::get_key())
    {
        case KEY_Q:
            exit(0);
        case KEY_H:
            break;
        case KEY_RIGHT:
            break;
        case KEY_LEFT:
            break;
        case KEY_DOWN:
            clear();
            GameLoop::set_active_scene(STATION);
            break;
        default:
            break;
    }
}

