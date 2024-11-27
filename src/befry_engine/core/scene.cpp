#include "config.h"

#include "core/scene.h"
#include "core/game_object.h"
#include "core/vector2.h"

#include <iostream>
#include <conio.h>
#include <unistd.h>


befry::Scene::Scene(callback_function tick_event): scene_event(tick_event) {}
befry::Scene::~Scene() = default;

void befry::Scene::clear()
{
	const Vector2 size = Config::get_scene_size();

	conio::console::clearScreen();
	conio::console::setCursorPosition(1, 1);
	conio::console::setBackgroundColor(BLACK);
	for (int y = 0; y <= size.Y+1; y++)
	{
		for (int x = 0; x <= size.X+1; x++)
			std::cout << " ";
		std::cout << std::endl;
	}
}

void befry::Scene::add_child(std::initializer_list<GameObject*> new_obj)
{
    for (GameObject* obj : new_obj)
        children.push_back(obj);
}
befry::GameObject* befry::Scene::get_child(std::string obj_name)
{
    for (GameObject* obj : children)
		if (obj->get_name() == obj_name)
			return obj;
	return nullptr;
}

void befry::Scene::render(Vector2 cur_res)
{
	const Vector2 size = Config::get_scene_size();

    if (cur_res < size+Vector2{2, 2})
    {
		clear();
		conio::console::setTextColor(RED);
        std::cout << "This scene requires a terminal size of " << size.X+2 << "x" << size.Y+2 << std::endl;\
        std::cout << "Your current resolution: " << cur_res.X << "x" << cur_res.Y << std::endl;
		conio::console::setTextColor(WHITE);
        return;
    }

	conio::console::setBackgroundColor(BLACK);
    for (int y = 0; y <= size.Y+1; y++)
    {
        for (int x = 0; x <= size.X+1; x++)
		{
			conio::console::setCursorPosition(x+1, y+1);
            if (x == 0 && y == 0) std::cout << "┌";
            else if (x == size.X+1 && y == 0) std::cout << "┐";
            else if (x == 0 && y == size.Y+1) std::cout << "└";
            else if (x == size.X+1 && y == size.Y+1) std::cout << "┘";
            else if (x == 0 || x == size.X+1) std::cout << "│";
            else if (y == 0 || y == size.Y+1) std::cout << "─";
		}
        std::cout << std::endl;
    }

    for (GameObject* obj : children)
        obj->update();
	usleep(1e6 / Config::get_scene_fps());
}

void befry::Scene::event()
{
	scene_event();
}

