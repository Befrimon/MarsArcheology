#pragma once

#include <string>

#include "../game_object.h"
#include "../scene.h"

#include "../utility/vector2.h"
#include "../utility/colors.h"

#ifndef SPRITE_H
#define SPRITE_H

namespace befry
{
    class Sprite : public GameObject
    {
    protected:
        const Scene *parent;

        Vector2 position{};
        Vector2 size{};
        std::string texture;
        const COLORS* color;

    private:
        void draw() const;

    public:
        Sprite(const Scene& root, const Vector2& pos, const std::string& tex = "default", const COLORS& clr = Default);
        ~Sprite();

        void set_texture(std::string tex);
        void update(const double& tick);
    };
}

#endif
