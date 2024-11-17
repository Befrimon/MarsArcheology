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

befry::Scene::Scene(Vector2 dim, conio::Console* con, int cfps): FPS(cfps), size(dim), console(con) {}

befry::Vector2 befry::Scene::rect() const
{
    return size;
}
void befry::Scene::add_children(std::initializer_list<GameObject*> new_obj)
{
    for (GameObject* obj : new_obj)
        objects.push_back(obj);
}
befry::GameObject* befry::Scene::get_child(int id)
{
    return objects[id];
}

void befry::Scene::render(Vector2 cur_res)
{
    console->setCursorPosition(1, 1);
    if (cur_res < size+Vector2{2, 2})
    {
        console->setTextColor(RED);
        std::cout << "This scene requires a terminal size of " << size.X+2 << "x" << size.Y+2 << std::endl;\
        std::cout << "Your current resolution: " << cur_res.X << "x" << cur_res.Y << std::endl;
        console->setTextColor(WHITE);
        return;
    }

    for (int y = 0; y <= size.Y+1; y++)
    {
        for (int x = 0; x <= size.X+1; x++)
            if (x == 0 && y == 0) std::cout << "┌";
            else if (x == size.X+1 && y == 0) std::cout << "┐";
            else if (x == 0 && y == size.Y+1) std::cout << "└";
            else if (x == size.X+1 && y == size.Y+1) std::cout << "┘";
            else if (x == 0 || x == size.X+1) std::cout << "│";
            else if (y == 0 || y == size.Y+1) std::cout << "─";
            else std::cout << " ";
        std::cout << std::endl;
    }

    for (GameObject* obj : objects)
        obj->update(console);

    #ifdef _WIN32
        Sleep(1e3 / FPS);
    #else
        usleep(1e6 / FPS);
    #endif
}
