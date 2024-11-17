#include "core/game_object.h"
#include "game_objects/sprite.h"

#include "core/vector2.h"
#include "core/scene.h"

#include <iostream>
#include <fstream>
#include <conio.h>

befry::Sprite::Sprite(
    const Vector2& root_size,
    const Vector2& pos, const std::string& tex
): GameObject(root_size)
{

    position = pos;
    if (tex.empty()) texture = "###\n###\n###";
    else texture = tex;
    color = WHITE;

    size = Vector2{0, 0};
}
befry::Sprite::~Sprite() = default;

void befry::Sprite::draw(conio::Console* console) const
{
    if (texture.empty()) return;

    std::string tmp;
    std::ifstream fin(texture + ".txt");
    for (int i = position.Y+1; i <= screen_size.Y+1 && std::getline(fin, tmp); i++)
    {
        console->setCursorPosition(position.X, i);
        console->setTextColor(color);
        std::cout << tmp << std::endl;
        console->setTextColor(WHITE);
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

void befry::Sprite::update(conio::Console* console) {
    draw(console);
}
