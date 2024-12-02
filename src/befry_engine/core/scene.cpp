#include "core/scene.h"
#include "core.h"

#include <conio.h>
#include <iostream>

befry::Scene::Scene()
{
    Core::clear();
}

void befry::Scene::render()
{
    const Vector2 size = Core::get_scene_size();
    Vector2 cur_res{};
    conio::console::getTerminalSize(cur_res.X, cur_res.Y);

    if (cur_res < size+Vector2{2, 2})
    {
        Core::clear();
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
}

