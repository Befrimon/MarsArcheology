#include "user_interface/canvas_item.h"
#include "user_interface/button.h"

#include "core/vector2.h"
#include "core/scene.h"

befry::Button::Button(const std::string& obj_name,
                      const Vector2& pos, const Vector2& res,
                      const std::string& text
): befry::CanvasItem(obj_name, pos, res), disabled(false), selected(false)
{
    content = text;
}
befry::Button::~Button() = default;

void befry::Button::draw()
{
	CanvasColor old = color;
	if (disabled)
        color = disabled_color;
    else if (selected)
    	color = active_color;
    CanvasItem::draw();
	color = old;

	int start_x = 0;
	if (size.X - content.length() > 0)
		start_x = (size.X - content.length()) / 2;
	conio::console::setCursorPosition(position.X + start_x, position.Y + size.Y / 2);

    if (disabled)
    {
		conio::console::setBackgroundColor(disabled_color.bg_color);
		conio::console::setTextColor(disabled_color.fg_color);
    }
    else if (selected)
    {
		conio::console::setBackgroundColor(active_color.bg_color);
		conio::console::setTextColor(active_color.fg_color);
    }
    else
    {
		conio::console::setBackgroundColor(color.bg_color);
		conio::console::setTextColor(color.fg_color);
    }
		
    for (int i = 0; i < content.length() && i < size.X; i++)
        std::cout << content[i];

	conio::console::setBackgroundColor(RESET);
	conio::console::setTextColor(WHITE);
    std::cout << std::endl;
}

void befry::Button::set_content(const std::string& text)
{
    content = text;
}

void befry::Button::set_selected(const bool& value)
{
    selected = value;
}
void befry::Button::set_disabled(const bool& value)
{
    disabled = value;
}

void befry::Button::set_disabled_bg(const short& clr)
{
    disabled_color.bg_color = clr;
}
void befry::Button::set_disabled_fg(const short& clr)
{
    disabled_color.fg_color = clr;
}
void befry::Button::set_active_bg(const short& clr)
{
    active_color.bg_color = clr;
}
void befry::Button::set_active_fg(const short& clr)
{
    active_color.fg_color = clr;
}

void befry::Button::on_press_action(callback_function new_func)
{
	on_click = new_func;
}
void befry::Button::pressed()
{
	on_click();
}


void befry::Button::update()
{
    draw();
}
