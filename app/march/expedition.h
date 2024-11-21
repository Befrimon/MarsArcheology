#pragma once

#include <string>
#include <vector>

#include <befry_engine.h>

#ifndef EXPEDITION_H
#define EXPEDITION_H

namespace march
{
	class Expedition
	{
	protected:
		const std::string name;
		const int level;

	public:
		Expedition() {}
		virtual ~Expedition();

		virtual void explore() = 0;
	};
}

#endif
