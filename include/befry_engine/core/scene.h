#pragma once

#include <vector>

#include "vector2.h"
#include "game_object.h"

#ifndef SCENE_H
#define SCENE_H

namespace befry
{
    class Scene
    {
    protected:
        std::vector<GameObject*> children;

    public:
        Scene();
        virtual ~Scene() = default;

        virtual GameObject& get_child(std::string obj_name) const = 0;

        virtual void render();
        virtual void event() = 0;
    };
}

#endif
