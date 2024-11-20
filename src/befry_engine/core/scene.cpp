#include "core/scene.h"
#include "core/game_object.h"
#include "core/vector2.h"

#include <iostream>
#include <conio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

befry::Scene::Scene(Vector2 dim, callback_function tick_event, int cfps): FPS(cfps), size(dim), scene_event(tick_event) {}
befry::Scene::~Scene() = default;

befry::Vector2 befry::Scene::rect() const
{
    return size;
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
    if (cur_res < size+Vector2{2, 2})
    {
		clear = true;
		conio::console->setTextColor(RED);
        std::cout << "This scene requires a terminal size of " << size.X+2 << "x" << size.Y+2 << std::endl;\
        std::cout << "Your current resolution: " << cur_res.X << "x" << cur_res.Y << std::endl;
		conio::console->setTextColor(WHITE);
        return;
    }

    for (int y = 0; y <= size.Y+1; y++)
    {
		conio::console->setBackgroundColor(BLACK);
        for (int x = 0; x <= size.X+1; x++)
		{
			conio::console->setCursorPosition(x+1, y+1);
            if (x == 0 && y == 0) std::cout << "┌";
            else if (x == size.X+1 && y == 0) std::cout << "┐";
            else if (x == 0 && y == size.Y+1) std::cout << "└";
            else if (x == size.X+1 && y == size.Y+1) std::cout << "┘";
            else if (x == 0 || x == size.X+1) std::cout << "│";
            else if (y == 0 || y == size.Y+1) std::cout << "─";
			else if (clear) std::cout << " ";
		}
		conio::console->setBackgroundColor(RESET);
        std::cout << std::endl;
    }
	clear = false;

    for (GameObject* obj : children)
        obj->update();

    #ifdef _WIN32
        Sleep(1e3 / FPS);
    #else
        usleep(1e6 / FPS);
    #endif
}

void befry::Scene::event()
{
	scene_event();
}

