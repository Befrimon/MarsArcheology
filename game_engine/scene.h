#pragma once

#include <vector>

#include "utility/vector2.h"
#include "game_objects/sprite.h"

#ifndef SCENE_H
#define SCENE_H

namespace befry
{
    class Sprite;

    class Scene
    {
    protected:
        int FPS;
        std::vector<Sprite*> objects;
        Vector2 size;

    public:
        explicit Scene(Vector2 dim, int cfps = 60);

        auto rect() const -> Vector2;

        void addSprite(std::initializer_list<Sprite*> new_sprites);
        void render(Vector2 cur_res);
    };
}

#endif
