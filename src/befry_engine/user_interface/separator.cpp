#include "user_interface/separator.h"
#include "core.h"

#include <iostream>
#include <conio.h>

befry::Separator::Separator(
    const std::string_view obj_name,
    const Vector2& pos, const int& len, const SepType &t
): CanvasItem(obj_name, pos, Vector2{}), type(t), length(len) {}

befry::Separator::~Separator() = default;

void befry::Separator::draw() const
{
    conio::console::setTextColor(RESET);
    if (type == VERTICAL)
        for (int y = position.Y; y < position.Y+length; y++)
        {
            conio::console::setCursorPosition(position.X, y);
            std::cout << "│";
        }
    else if (type == HORIZONTAL)
        for (int x = position.X; x < position.X+length; x++)
        {
            conio::console::setCursorPosition(x, position.Y);
            std::cout << "─";
        }
}

void befry::Separator::set_bg_color(const short& clr)
{
    color.bg_color = clr;
}

void befry::Separator::set_fg_color(const short& clr)
{
    color.fg_color = clr;
}

void befry::Separator::update()
{
    draw();
}
