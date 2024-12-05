#pragma once

#include <memory>
#include <vector>

#include "game_object.h"

#ifndef SCENE_H
#define SCENE_H

namespace befry
{
    class Scene
    {
    protected:
        std::vector<std::shared_ptr<GameObject>> children;

    public:
        Scene();
        virtual ~Scene() = default;

        std::shared_ptr<GameObject> get_child(std::string obj_name) const;

        static void clear();
        virtual int render();
        virtual void event() = 0;
    };
}

#endif
