#include "player.h"
#include "equip.h"

#include <string>
#include <cstdlib>
#include <ctime>

march::Player::Player()
{
	tools = {
		{"Shovel", "󰜐", 10, SHOVEL, 1},
		{"Pickaxe", "󰢷", 10, PICKAXE, 1},
		{"Brush", "", 10, BRUSH, 1}
	};
	level = 1;
	spacesuit = {100, 1, 1};
	max_hp = 2 + rand() % 4;
	hp = max_hp;
}

std::string march::Player::get_player_info()
{
	return
		std::to_string(level) + " level | 󰗶 " +
		std::to_string(hp) + "/" + std::to_string(max_hp) +
		" | " + std::to_string(money) + "$";
}
std::string march::Player::get_tools_info()
{
	std::string res = "";
	for (Tool tool : tools)
		res = res + "| " + tool.icon +
			" (" +std::to_string(tool.level) + ") - " +
			std::to_string(tools[0].durability / tools[0].level * tools[0].level * 10) + "% ";
	return res;
}
