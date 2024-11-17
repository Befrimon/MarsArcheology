#pragma once

#include <vector>

#include "utility/vector2.h"
#include "game_object.h"

#ifndef SCENE_H
#define SCENE_H

namespace befry
{
    class Sprite;

    class Scene
    {
    protected:
        int FPS;
        conio::Console* console;
        std::vector<GameObject*> objects;
        Vector2 size;

    public:
        explicit Scene(Vector2 dim, conio::Console* con, int cfps = 60);

        auto rect() const -> Vector2;

        void addSprite(std::initializer_list<GameObject*> new_sprites);
        void render(Vector2 cur_res);
    };
}

#endif
