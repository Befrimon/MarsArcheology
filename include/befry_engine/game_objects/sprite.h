#pragma once

#include <string>
#include <conio.h>

#include "game_object.h"
#include "scene.h"

#include "utility/vector2.h"

#ifndef SPRITE_H
#define SPRITE_H

namespace befry
{
    class Sprite : public GameObject
    {
    protected:
        const Scene* parent;

        Vector2 position{};
        Vector2 size{};
        std::string texture;
        const short* color;

    private:
        void draw(conio::Console* console) const;

    public:
        Sprite(const Scene& root, const Vector2& pos, const std::string& tex = "", const short& clr = WHITE);
        ~Sprite();

        void set_texture(std::string tex);
        void update(conio::Console* console);
    };
}

#endif
