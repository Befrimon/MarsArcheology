#pragma once

#include "core/vector2.h"
#include <conio.h>

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

namespace befry
{
    class Scene;

    class GameObject
    {
    protected:
        const Vector2 screen_size;
        
        virtual void draw(conio::Console* console) const = 0;

    public:
        explicit GameObject(const Vector2& root_size): screen_size(root_size) {}
        virtual ~GameObject();

        virtual void update(conio::Console* console) = 0;
    };
    inline GameObject::~GameObject() {};

}

#endif
