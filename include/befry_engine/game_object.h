#pragma once

#include <conio.h>

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

namespace befry
{
    class Scene;

    class GameObject
    {
    protected:
        const Scene* parent;

    public:
        explicit GameObject(const Scene& root): parent(&root){}
        virtual ~GameObject();

        virtual void update(Console* console) = 0;
    };
    inline GameObject::~GameObject() {};

}

#endif
