#include "expeditions/wasteland.h"

#include <fstream>

march::Wasteland::Wasteland() = default;
march::Wasteland::~Wasteland() = default;

void march::Wasteland::effect() {}

void march::Wasteland::explore(befry::Vector2 coord)
{
    Expedition::explore(coord);

    std::ofstream fout(befry::Core::get_game_dir() + "cur_tile.txt");

    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 15; x++)
            fout << get_tile({x, y});
        fout << std::endl;
    }

    fout.close();
}
std::string march::Wasteland::get_tile(befry::Vector2 coord)
{
    return Expedition::get_tile(coord);
}