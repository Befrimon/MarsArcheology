#include "../game_object.h"
#include "sprite.h"

#include "../utility/vector2.h"
#include "../utility/colors.h"
#include "../scene.h"

#include <iostream>
#include <fstream>

befry::Sprite::Sprite(const Scene& root, const Vector2& pos, const std::string& tex, const COLORS& clr): GameObject(root) {
    parent = &root;
    position = pos;
    texture = tex;
    color = &clr;

    size = Vector2{0, 0};
}

befry::Sprite::~Sprite() = default;


void befry::Sprite::draw() const
{
    if (texture.empty()) return;

    std::string tmp;
    std::ifstream fin("textures/" + texture +".txt");
    for (int i = position.Y; i <= parent->rect().X && std::getline(fin, tmp); i++)
        std::cout << "\033[" << std::to_string(i) << ";" << std::to_string(position.X) << "H"
            << to_string(*color) << tmp << RESET << std::endl;
    fin.close();
}

void befry::Sprite::set_texture(std::string tex) { texture = tex; }

void befry::Sprite::update(const double &tick)
{
    draw();
}
