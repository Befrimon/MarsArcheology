#pragma once

#include <string>

#ifndef ITEM_H
#define ITEM_H

namespace march
{
	enum ToolType {SHOVEL, PICKAXE, BRUSH};

	struct Tool
	{
		std::string name;
		std::string icon;
		int durability;
		int efficiency;
		int type;
		int level;
	};

	struct Suit
	{
		std::string name;
		double oxygen;
		int warm_coef;
		int level;
	};

	struct Item
	{
		std::string name;
		int weight;
		int level;
		int cost;
	};

	struct Food
	{
		std::string name;
		int cost;
		int weight;
	};
}

#endif
