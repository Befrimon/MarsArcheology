#include "sprites/map.h"

#include <befry_engine.h>
#include <conio.h>
#include "player.h"

march::Map::Map(const std::string& obj_name, const befry::Vector2& pos, const MapMode& m, const int& rect)
: Sprite(obj_name, pos)
{
    size = befry::Vector2{rect, rect};
    color = YELLOW;
    mode = m;
}
march::Map::~Map() = default;

void march::Map::draw() const
{
    if (mode == MINI)
    {
        Sprite::draw();
        return;
    }

    for (int y = position.Y; y < position.Y + size.Y; y++)
    {
        for (int x = position.X; x < position.X + size.X*2; x+=2)
        {
            conio::console::setCursorPosition(x, y);
            if (mode == GLOBAL && (befry::Vector2{x, y} == position + Player::get_position() || befry::Vector2{x+1, y} == position + Player::get_position()))
            {
                conio::console::setTextColor(GREEN);
                std::cout << tiles[mode][1];
            }
            else
            {
                conio::console::setTextColor(color);
                std::cout << tiles[mode][0];
            }
            conio::console::setTextColor(RESET);
        }
        std::cout << std::endl;
    }
}

