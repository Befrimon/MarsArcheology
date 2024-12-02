#include "user_interface/button_group.h"
#include "user_interface/button.h"

befry::ButtonGroup::ButtonGroup()
{
    current = 0;
}
befry::ButtonGroup::~ButtonGroup() = default;

void befry::ButtonGroup::add_button(
    std::string_view obj_name,
    const Vector2& pos,const Vector2& size,
    std::string_view text
) {
    buttons.emplace_back(obj_name, pos, size, text);
}
void befry::ButtonGroup::set_current(int id)
{
    if (id >= buttons.size()) return;
    buttons[current].set_selected(false);
    buttons[id].set_selected(true);
    current = id;
}
befry::Button befry::ButtonGroup::get_current() const
{
    return buttons[current];
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
