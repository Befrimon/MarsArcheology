#pragma once

#include <vector>
#include <string>

#include <befry_engine.h>
#include "equip.h"

#ifndef PLAYER_H
#define PLAYER_H

namespace march
{
	class Player
	{
	protected:
		std::vector<Tool*> tools;
		Suit* spacesuit;

		int level;
		int money;
		int max_hp;
		int hp;

	public:
		Player();
		~Player();

		std::string get_player_info() const;
		std::string get_tools_info() const;

		Tool* get_tool(const int &id) const;
		Suit* get_suit() const;

	};
}

#endif
