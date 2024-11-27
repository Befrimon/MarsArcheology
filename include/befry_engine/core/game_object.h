#pragma once

#include <string>

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

namespace befry
{
	typedef void (*callback_function)(void);

    class Scene;

    class GameObject
    {
    protected:
		const std::string name;
        
        virtual void draw() const = 0;

    public:
        explicit GameObject(const std::string& obj_name): name(obj_name) {}
        virtual ~GameObject();

		virtual std::string get_name() const = 0;
        virtual void update() = 0;
    };
    inline GameObject::~GameObject() {};

}

#endif
