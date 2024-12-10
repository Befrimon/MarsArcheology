#include "core.h"

#include <fstream>
#include <iostream>
#include <conio.h>
#include <filesystem>
#include <map>

std::string befry::Core::texture_path;
befry::Vector2 befry::Core::scene_size;
int befry::Core::scene_fps;
std::string befry::Core::game_dir;

void befry::Core::read_config(std::string_view path)
{
    /* Read file */
    std::ifstream fin(static_cast<std::string>(std::filesystem::current_path()) + std::string(path));
    std::map<std::string, std::string> values;
    std::string cur_line;
    while (getline(fin, cur_line))
        values[cur_line.substr(0, cur_line.find_first_of('='))] = cur_line.substr(cur_line.find_first_of('=')+1, cur_line.length());
    fin.close();

    texture_path = static_cast<std::string>(std::filesystem::current_path()) + values["TEXTURES_PATH"];
    scene_size = str_to_vector2(values["SCENE_SIZE"]);
    scene_fps = std::atoi(values["SCENE_FPS"].c_str());
    game_dir = getenv("HOME") + values["GAME_DIR"];
    if (!std::filesystem::exists(game_dir))
        std::filesystem::create_directory(game_dir);
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

std::string befry::Core::get_game_dir()
{
    return game_dir;
}

