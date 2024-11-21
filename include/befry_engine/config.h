#pragma once

#include "core/vector2.h"
#include <string>

#ifndef CONFIG_H
#define CONFIG_H

namespace befry
{
	class Config
	{
	private:
		Config() {}

		/* Variables */
		static std::string texture_path;
		static Vector2 scene_size;
		static int scene_fps;

	public:
		/* get and set */
		static void set_texture_path(std::string val);
		static std::string get_texture_path();

		static void set_scene_size(Vector2 val);
		static Vector2 get_scene_size();

		static void set_scene_fps(int val);
		static int get_scene_fps();
	};
}

#endif
