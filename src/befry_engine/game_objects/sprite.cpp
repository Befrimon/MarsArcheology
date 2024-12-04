#include "core.h"

#include "core/game_object.h"
#include "game_objects/sprite.h"

#include "core/vector2.h"

#include <string_view>
#include <iostream>
#include <fstream>
#include <conio.h>


/* Constructor and destructor */
befry::Sprite::Sprite(
    std::string_view obj_name,
    const Vector2& pos, std::string_view tex
): GameObject(obj_name), position(pos + Vector2{1, 1}),
    texture(std::string(Core::get_texture_path()) + std::string(tex) + ".txt") {}
befry::Sprite::~Sprite() = default;

/* Private */
void befry::Sprite::draw() const
{
    if (texture.empty()) return;

    std::string tmp;
    std::ifstream fin(texture);
    for (int y = position.Y; std::getline(fin, tmp); y++)
    {
        conio::console::setCursorPosition(position.X, y);
        conio::console::setTextColor(color);
        std::cout << tmp << std::endl;
        conio::console::setTextColor(RESET);
    }
    fin.close();
}

/* Public */
void befry::Sprite::set_texture(std::string_view tex)
{
    texture = tex;
}
void befry::Sprite::set_color(const short& clr)
{
    color = clr;
}

std::string_view befry::Sprite::get_name() const
{
    return name;
}
void befry::Sprite::update()
{
    draw();
}
