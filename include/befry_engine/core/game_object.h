#pragma once

#include <string>
#include <string_view>

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

namespace befry
{
    class GameObject
    {
    protected:
		const std::string name;

        virtual void draw() const = 0;

    public:
        explicit GameObject(std::string_view obj_name) {}
        virtual ~GameObject() = default;

		virtual std::string_view get_name() const = 0;
        virtual void update() = 0;
    };
}

#endif
