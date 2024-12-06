#include "player.h"
#include <sstream>

befry::Vector2 march::Player::position = befry::Vector2{10, 1};
std::vector<march::Tool> march::Player::tools =
{
    Tool{"Pickaxe", 10, 10, 1},
    Tool{"Shovel", 10, 10, 1},
    Tool{"Brush", 10, 10, 1},
};
int march::Player::level = 1;
int march::Player::money = 50 + std::rand() % 51;

int hit = 2 + std::rand() % 4;
befry::CurMax<int> march::Player::hits = befry::CurMax<int>{hit, hit};

befry::Vector2 march::Player::get_position()
{
    return position;
}

void march::Player::move(befry::Vector2 delta)
{
    position = position + delta;
}

march::Tool march::Player::get_tool(PlrTools tool)
{
    return tools[tool];
}

std::string march::Player::get_info()
{
    std::stringstream res;
    res << level << " level | 󰗶 " << hits.value << "/" << hits.max_value << " | " << money << "$";
    return res.str();
}
std::string march::Player::get_tool_info()
{
    std::stringstream res;
    res << "󰜐 (" << tools[SHOVEL].level << ") - " << tools[SHOVEL].durability.value * 100 / tools[SHOVEL].durability.max_value << "% | "
        << "󰢷 (" << tools[PICKAXE].level << ") - " << tools[PICKAXE].durability.value * 100 / tools[PICKAXE].durability.max_value << "% | "
        << " (" << tools[BRUSH].level << ") - " << tools[BRUSH].durability.value * 100 / tools[BRUSH].durability.max_value << "%";
    return res.str();
}

