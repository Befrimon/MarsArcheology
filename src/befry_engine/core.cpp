#include "core.h"

#include <fstream>
#include <iostream>
#include <conio.h>
#include <filesystem>

std::string befry::Core::texture_path;
befry::Vector2 befry::Core::scene_size;
int befry::Core::scene_fps;

void befry::Core::read_config(std::string_view path)
{
    // TODO Read config file
    texture_path = static_cast<std::string>(std::filesystem::current_path()) +"/textures/";
    scene_size = Vector2{140, 40};
    scene_fps = 12;
}

void befry::Core::clear()
{
    conio::console::clearScreen();
    conio::console::setBackgroundColor(BLACK);
    for (int y = 0; y <= scene_size.Y+1; y++)
    {
        for (int x = 0; x <= scene_size.X+1; x++)
        {
            conio::console::setCursorPosition(x+1, y+1);
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

std::string_view befry::Core::get_texture_path()
{
    return texture_path;
}

befry::Vector2 befry::Core::get_scene_size()
{
    return scene_size;
}

int befry::Core::get_scene_fps()
{
    return scene_fps;
}