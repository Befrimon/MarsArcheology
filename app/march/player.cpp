#include "player.h"
#include "equip.h"

#include <string>
#include <cstdlib>

march::Player::Player()
{
	tools = {
		new Tool{"Shovel", "󰜐", 10, 1, SHOVEL, 1},
		new Tool{"Pickaxe", "󰢷", 10, 1, PICKAXE, 1},
		new Tool{"Brush", "", 10, 1, BRUSH, 1}
	};
	level = 1;
	spacesuit = new Suit{"Not empty", 100.0, 1, 1};
	money = 50 + std::rand() % 51;
	max_hp = 2 + std::rand() % 4;
	hp = max_hp;
}

march::Player::~Player() = default;

std::string march::Player::get_player_info() const
{
	return
		std::to_string(level) + " level | 󰗶 " +
		std::to_string(hp) + "/" + std::to_string(max_hp) +
		" | " + std::to_string(money) + "$ |";
}
std::string march::Player::get_tools_info() const
{
	std::string res;
	for (Tool* tool : tools)
		res += "| " + tool->icon +
			" (" +std::to_string(tool->level) + ") - " +
			std::to_string(tools[0]->durability / tools[0]->level * tools[0]->level * 10) + "% ";
	return res;
}

march::Tool* march::Player::get_tool(const int& id) const { return tools[id]; }
march::Suit* march::Player::get_suit() const { return spacesuit; }

