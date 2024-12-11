#include "user_interface/canvas_item.h"
#include "user_interface/button.h"
#include "core/vector2.h"
#include "core/scene.h"

#include <sstream>
#include <iostream>
#include <conio.h>

befry::Button::Button(const std::string_view obj_name,
                      const Vector2& pos, const Vector2& res,
                      const std::string_view text
): CanvasItem(obj_name, pos, res),
    disabled(false), selected(false), event(nullptr), content(text),
    active_color{BLACK, GREEN}, disabled_color{BLACK, GRAY}
{}

befry::Button::~Button() = default;

void befry::Button::draw() const
{
    CanvasColor cur = disabled ? disabled_color : (selected ? active_color : color);

    for (int y = position.Y-1; y <= position.Y + size.Y; y++)
    {
        conio::console::setCursorPosition(position.X-1, y);
        conio::console::setBackgroundColor(cur.bg_color);
        conio::console::setTextColor(cur.fg_color);
        for (int x = position.X-1; x <= position.X + size.X; x++)
            if 		(x == position.X-1 && y == position.Y-1) 			std::cout << "┌";
            else if (x == position.X+size.X && y == position.Y-1) 		std::cout << "┐";
            else if (x == position.X-1 && y == position.Y+size.Y) 		std::cout << "└";
            else if (x == position.X+size.X && y == position.Y+size.Y) 	std::cout << "┘";
            else if (x == position.X-1 || x == position.X+size.X) 		std::cout << "│";
            else if (y == position.Y-1 || y == position.Y+size.Y) 		std::cout << "─";
            else 														std::cout << " ";
        conio::console::setBackgroundColor(BLACK);
        conio::console::setTextColor(RESET);
        std::cout << std::endl;
    }

    std::vector<std::string> lines;
    std::stringstream ss(content);
    std::string line;
    while (!ss.eof())
    {
        std::getline(ss, line, '\n');
        lines.push_back(line);
    }

    for (int y = 0; y < lines.size(); y++)
    {
        int pos_x = (size.X - static_cast<int>(lines[y].length())) / 2;
        int pos_y = (size.Y - static_cast<int>(lines.size())) / 2 + y;

        conio::console::setCursorPosition(position.X+pos_x, position.Y+pos_y);
        conio::console::setBackgroundColor(cur.bg_color);
        conio::console::setTextColor(cur.fg_color);
        std::cout << lines[y];
        conio::console::setBackgroundColor(BLACK);
        conio::console::setTextColor(RESET);
        std::cout << std::endl;
    }

}

std::string_view befry::Button::get_name() const
{
    return name;
}

void befry::Button::set_content(const std::string_view text)
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

void befry::Button::set_bg_color(const short& clr)
{
    color.bg_color = clr;
}
void befry::Button::set_fg_color(const short& clr)
{
    color.fg_color = clr;
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

void befry::Button::connect(void (*func)())
{
    event = func;
}
void befry::Button::click()
{
    event();
}


void befry::Button::update()
{
    draw();
}
