#include "expeditions/expedition.h"

march::Expedition::Expedition()
{
    cur_tile.resize(size);
    for (int y = 0; y < size; y++)
        cur_tile[y].resize(size);
}

void march::Expedition::explore(befry::Vector2 coord)
{
    const siv::PerlinNoise perlin{ static_cast<siv::BasicPerlinNoise<double>::seed_type>(100*coord.X + coord.Y) };

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cur_tile[y][x] = perlin.octave2D_01(x, y, 64, .4);
}
std::string march::Expedition::get_tile(befry::Vector2 coord)
{
    return cur_tile[coord.Y][coord.X] < .25 ? "**" : "##";
}