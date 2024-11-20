#include "user_interface/button_group.h"
#include "user_interface/button.h"

befry::ButtonGroup::ButtonGroup()
{
	current = 0;
}
befry::ButtonGroup::~ButtonGroup() = default;

void befry::ButtonGroup::add_buttons(std::initializer_list<Button*> new_btns)
{
    for (Button* btn : new_btns)
        buttons.push_back(btn);
	buttons[0]->set_selected(true);
}
void befry::ButtonGroup::set_current(int id)
{
	if (id >= buttons.size()) return;
	buttons[current]->set_selected(false);
	buttons[id]->set_selected(true);
	current = id;
}
void befry::ButtonGroup::prev()
{
	if (current > 0)
		set_current(current-1);
}
void befry::ButtonGroup::next()
{
	if (current < buttons.size()-1)
		set_current(current+1);
}
befry::Button* befry::ButtonGroup::get_current() const
{
	return buttons[current];
}
