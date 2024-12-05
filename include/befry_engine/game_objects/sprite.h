#pragma once

#include <string>
#include <string_view>

#include "../conio/conio.h"
#include "core/game_object.h"
#include "core/vector2.h"

#ifndef SPRITE_H
#define SPRITE_H

namespace befry
{
    class Sprite : public GameObject
    {
    protected:
        Vector2 position;
        Vector2 size{1, 1};
        std::string texture;
        short color = RESET;

        void draw() const override;

    public:
        Sprite(std::string_view obj_name, const Vector2& pos, std::string_view tex = "");
        ~Sprite() override;

        virtual void set_texture(std::string_view tex);
        void set_color(const short& clr);

        std::string_view get_name() const override;
        void update() override;
    };
}

#endif
