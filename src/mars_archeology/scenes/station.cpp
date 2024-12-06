#include "scenes/station.h"
#include "loop.h"
#include "player.h"

#include <befry_engine.h>

march::Station::Station()
{
    children.push_back(std::make_shared<befry::Sprite>("Background", befry::Vector2{1, 1}, "stantion"));
    children.push_back(std::make_shared<befry::Label>("Hint", befry::Vector2{1, 1}, befry::Vector2{140, 1}, "Press \'h\' to open help"));
    children.push_back(std::make_shared<befry::Label>("PlayerInfo", befry::Vector2{1, 1}, befry::Vector2{143, 1}, "", befry::West));
    children.push_back(std::make_shared<befry::Label>("ToolsInfo", befry::Vector2{1, 1}, befry::Vector2{148, 1}, "", befry::East));
    children.push_back(std::make_shared<befry::Label>("ControlsInfo", befry::Vector2{1, 40}, befry::Vector2{152, 1}, " Museum |  New expedition  | Shop "));

    std::static_pointer_cast<befry::Label>(get_child("Hint"))->set_fg_color(YELLOW);
    std::static_pointer_cast<befry::Label>(get_child("PlayerInfo"))->set_fg_color(RED);
    std::static_pointer_cast<befry::Label>(get_child("ToolsInfo"))->set_fg_color(RED);
}
march::Station::~Station() = default;

int march::Station::render()
{
    if (Scene::render() == -1)
        return -1;

    std::static_pointer_cast<befry::Label>(get_child("PlayerInfo"))->set_content(Player::get_info());
    std::static_pointer_cast<befry::Label>(get_child("ToolsInfo"))->set_content(Player::get_tool_info());

    for (std::shared_ptr<befry::GameObject> obj : children)
        obj->update();

    return 0;
}

void march::Station::event()
{
    /*
    dynamic_cast<befry::Label*>(scenes[STATION]->get_child("PlayerInfo"))->set_content(plr->get_player_info());
    dynamic_cast<befry::Label*>(scenes[STATION]->get_child("ToolsInfo"))->set_content(plr->get_tools_info());
    */

    if (conio::console::kbhit()) switch(befry::Input::get_key())
    {
        case KEY_Q:
            exit(0);
        case KEY_H:
            break;
        case KEY_UP:
            clear();
            GameLoop::set_active_scene(PLANET);
            break;
        case KEY_RIGHT:
            clear();
            GameLoop::set_active_scene(SHOP);
            break;
        case KEY_LEFT:
            clear();
            GameLoop::set_active_scene(MUSEUM);
            break;
        default:
            break;
    }
}

