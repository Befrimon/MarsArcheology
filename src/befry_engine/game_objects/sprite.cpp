#include "game_object.h"
#include "game_objects/sprite.h"

#include "utility/vector2.h"
#include "scene.h"

#include <iostream>
#include <fstream>
#include <conio.h>

befry::Sprite::Sprite(const Scene& root, const Vector2& pos, const std::string& tex, const short& clr): GameObject(root) {
    parent = &root;
    position = pos;
    if (tex.empty()) texture = "###\n###\n###";
    else texture = tex;
    color = &clr;

    size = Vector2{0, 0};
}

befry::Sprite::~Sprite() = default;


void befry::Sprite::draw(conio::Console* console) const
{
    if (texture.empty()) return;

    std::string tmp;
    std::ifstream fin(texture + ".txt");
    for (int i = position.Y; i <= parent->rect().Y && std::getline(fin, tmp); i++)
    {
        console->setCursorPosition(position.X, i);
        console->setTextColor(*color);
        std::cout << tmp << std::endl;
        console->setTextColor(WHITE);
    }
    fin.close();
}

void befry::Sprite::set_texture(std::string tex) { texture = tex; }


void befry::Sprite::update(conio::Console* console) {
    draw(console);
}
