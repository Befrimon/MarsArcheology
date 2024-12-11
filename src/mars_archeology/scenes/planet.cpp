#include "scenes/planet.h"

#include <befry_engine.h>
#include <sstream>
#include <expeditions/wasteland.h>
#include <sprites/toolbox.h>

#include "player.h"
#include "sprites/map.h"

march::Planet::Planet()
{
    children.push_back(std::make_shared<befry::Separator>("FirstSeparator", befry::Vector2{1, 31}, 78, befry::HORIZONTAL));
    children.push_back(std::make_shared<befry::Separator>("SecondSeparator", befry::Vector2{79, 1}, 40, befry::VERTICAL));
    children.push_back(std::make_shared<befry::Separator>("ThirdSeparator", befry::Vector2{80, 16}, 61, befry::HORIZONTAL));
    children.push_back(std::make_shared<Map>("MainMap", befry::Vector2{10, 1}, GLOBAL, 30));
    children.push_back(std::make_shared<Map>("MiniMap", befry::Vector2{95, 1}, MINI, 15));

    children.push_back(std::make_shared<befry::Label>("TerrainInfo", befry::Vector2{1, 32}, befry::Vector2{78, 3}, " Temp -15°C ▼\n Time 6:00 AM\n󱐟 Food 99 days", befry::West));
    children.push_back(std::make_shared<Toolbox>("Brush", befry::Vector2{83, 18}));
    children.push_back(std::make_shared<Toolbox>("Shovel", befry::Vector2{83, 24}));
    children.push_back(std::make_shared<Toolbox>("Pickaxe", befry::Vector2{83, 30}));
    children.push_back(std::make_shared<Toolbox>("Suit", befry::Vector2{83, 36}));
}
march::Planet::~Planet() = default;

int march::Planet::render()
{
    if (Scene::render() == -1)
        return -1;

    for (std::shared_ptr<befry::GameObject> obj : children)
        obj->update();

    return 0;
}

void march::Planet::update_map()
{
    exp_type->explore(Player::get_position());
    std::static_pointer_cast<Map>(get_child("MiniMap"))->set_texture(befry::Core::get_game_dir() + "cur_tile", true);
}

void march::Planet::event()
{
    if (conio::console::kbhit()) switch(befry::Input::get_key())
    {
        case KEY_Q:
            exit(0);
        case KEY_RIGHT:
            Player::move(befry::Vector2{2, 0});
            update_map();
            break;
        case KEY_LEFT:
            Player::move(befry::Vector2{-2, 0});
            update_map();
            break;
        case KEY_DOWN:
            Player::move(befry::Vector2{0, 1});
            update_map();
            break;
        case KEY_UP:
            Player::move(befry::Vector2{0, -1});
            update_map();
            break;
        default: break;
    }
}

void march::Planet::start_expedition(TYPE type)
{
    switch (type)
    {
        case WASTELAND:
            exp_type = std::make_shared<Wasteland>();
            update_map();
            break;
        default: break;
    }
}
