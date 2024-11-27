#include "config.h"

#include "core/game_object.h"
#include "game_objects/sprite.h"

#include "core/vector2.h"
#include "core/scene.h"

#include <iostream>
#include <fstream>
#include <conio.h>


befry::Sprite::Sprite(
    const std::string& obj_name,
    const Vector2& pos, const std::string& tex
): GameObject(obj_name)
{
    position = pos + Vector2{1, 1};
    texture = Config::get_texture_path() + tex;
    color = WHITE;

    size = Vector2{0, 0};
}
befry::Sprite::~Sprite() = default;
std::string befry::Sprite::get_name() const { return name; }

void befry::Sprite::draw() const
{
    if (texture.empty()) return;

    std::string tmp;
    std::ifstream fin(texture + ".txt");
    for (int y = position.Y; std::getline(fin, tmp); y++)
    {
		conio::console::setCursorPosition(position.X, y);
		conio::console::setTextColor(color);
        std::cout << tmp << std::endl;
		conio::console::setTextColor(WHITE);
    }
    fin.close();
}

void befry::Sprite::set_texture(std::string tex)
{
    texture = tex;
}
void befry::Sprite::set_color(const short& clr)
{
    color = clr;
}

void befry::Sprite::update() {
    draw();
}
