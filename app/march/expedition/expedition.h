#pragma once

#include <string>
#include <vector>

#include "../player.h"
#include "../equip.h"
#include "../items/artefact.h"

#include <befry_engine.h>


#ifndef EXPEDITION_H
#define EXPEDITION_H

namespace march
{
	enum ExpType {WASTELAND};

	class Expedition
	{
	protected:
		ExpType type;
		std::string name;
		int level;
		double temperature;
		int time;

		Player* player_ptr;
		std::vector<Artefact> total_finds;
		std::vector<Artefact> current_finds;

		void wasteland();

	public:
		Expedition(Player* plr, ExpType t);
		~Expedition();

		std::string explore(ToolType tool, befry::Vector2 pos);
		std::string event();
	};
}

#endif
