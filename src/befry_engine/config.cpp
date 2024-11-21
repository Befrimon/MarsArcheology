#include "config.h"
#include "core/vector2.h"
#include <string>

std::string befry::Config::texture_path = "";
befry::Vector2 befry::Config::scene_size = befry::Vector2{10, 10};
int befry::Config::scene_fps = 24;

void befry::Config::set_texture_path(std::string val)
{
	texture_path = val;
}
std::string befry::Config::get_texture_path()
{
	return texture_path;
}

void befry::Config::set_scene_size(Vector2 val)
{
	scene_size = val;
}
befry::Vector2 befry::Config::get_scene_size()
{
	return scene_size;
}

void befry::Config::set_scene_fps(int val)
{
	scene_fps = val;
}
int befry::Config::get_scene_fps()
{
	return scene_fps;
}
