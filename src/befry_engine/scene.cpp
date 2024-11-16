#include "scene.h"

#include "utility/vector2.h"
#include <iostream>
#include <conio.h>

#ifdef _WIN32 || _WIN64
#include <windows.h>
#else
#include <unistd.h>
#endif

befry::Scene::Scene(Vector2 dim, Console* con, int cfps): FPS(cfps), size(dim), console(con) {}

befry::Vector2 befry::Scene::rect() const { return size; };
void befry::Scene::addSprite(std::initializer_list<Sprite*> new_sprites)
{
    for (Sprite* obj : new_sprites)
        objects.push_back(obj);
}

void befry::Scene::render(Vector2 cur_res)
{
    console->setCursorPosition(1, 1);
    if (cur_res < size)
    {
        std::cout << "This scene requires a terminal size of " << size.X << "x" << size.Y << std::endl;\
        std::cout << "Your current resolution: " << cur_res.X << "x" << cur_res.Y << std::endl;
        return;
    }
    for (int y = 0; y < size.Y; y++)
    {
        for (int x = 0; x < size.X; x++)
            if (x == 0 && y == 0) std::cout << "┌";
            else if (x == size.X-1 && y == 0) std::cout << "┐";
            else if (x == 0 && y == size.Y-1) std::cout << "└";
            else if (x == size.X-1 && y == size.Y-1) std::cout << "┘";
            else if (x == 0 || x == size.X-1) std::cout << "│";
            else if (y == 0 || y == size.Y-1) std::cout << "─";
            else std::cout << " ";
        std::cout << std::endl;
    }

    for (Sprite* obj : objects)
        obj->update(console);

    usleep(1e7 / FPS);
}
