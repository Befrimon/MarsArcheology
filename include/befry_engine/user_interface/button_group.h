#pragma once

#include <vector>
#include "user_interface/button.h"

#ifndef BUTTON_GROUP_H
#define BUTTON_GROUP_H

namespace befry
{
	class ButtonGroup
	{
		protected:
			int current;
			std::vector<Button*> buttons;

		public:
			ButtonGroup();
			~ButtonGroup();

			void add_buttons(std::initializer_list<Button*> new_btns);
			void set_current(int id);
			void prev();
			void next();
			Button* get_current() const;
	};
}

#endif
