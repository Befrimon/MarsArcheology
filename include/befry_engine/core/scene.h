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
        int FPS;
		bool clear = true;
        std::vector<GameObject*> children;
        Vector2 size;
		callback_function scene_event;

    public:
        explicit Scene(Vector2 dim, callback_function tick_event, int cfps = 24);
		~Scene();

        auto rect() const -> Vector2;

        void add_child(std::initializer_list<GameObject*> new_obj);
        GameObject* get_child(std::string obj_name);
        void render(Vector2 cur_res);
		void event();
    };
}

#endif
