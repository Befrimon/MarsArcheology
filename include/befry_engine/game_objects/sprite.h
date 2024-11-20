#pragma once

#include <string>
#include <conio.h>

#include "core/game_object.h"
#include "core/scene.h"
#include "core/vector2.h"

#ifndef SPRITE_H
#define SPRITE_H

namespace befry
{
    class Sprite : public GameObject
    {
    protected:
        Vector2 position{};
        Vector2 size{};
        std::string texture;
        short color;

        void draw() const;

    public:
        Sprite(const std::string& obj_name, const Vector2& pos, const std::string& tex = "");
        ~Sprite();

        void set_texture(std::string tex);
        void set_color(const short& clr);

		std::string get_name() const;
        void update();
    };
}

#endif
