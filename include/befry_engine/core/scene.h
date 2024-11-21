#pragma once

#include <vector>

#include "core/vector2.h"
#include "core/game_object.h"

#ifndef SCENE_H
#define SCENE_H

namespace befry
{
    class Sprite;

    class Scene
    {
    protected:
        std::vector<GameObject*> children;
		callback_function scene_event;

    public:
        explicit Scene(callback_function tick_event);
		~Scene();

        static void clear();

        void add_child(std::initializer_list<GameObject*> new_obj);

        GameObject* get_child(std::string obj_name);

		void render(Vector2 cur_res);
		void event();
    };
}

#endif
