#include "user_interface/canvas_item.h"
#include "core/game_object.h"
#include "core/scene.h"

#include <iostream>

befry::CanvasItem::CanvasItem(
    const Vector2& root_size,
    const befry::Vector2& pos, const befry::Vector2& res
): GameObject(root_size)
{
    position = pos;
    size = res;
    color = {BLACK, WHITE};
    borderless = false;
}
befry::CanvasItem::~CanvasItem() = default;

void befry::CanvasItem::draw(conio::Console* console) const
{
    std::string tmp;
    for (int y = position.Y; y < position.Y + size.Y && y <= screen_size.Y && !borderless; y++)
    {
        console->setCursorPosition(position.X, y);
        console->setBackgroundColor(color.bg_color);
        console->setTextColor(color.fg_color);
        for (int x = position.X; x < position.X + size.X && x <= screen_size.X; x++)
            if (position == Vector2{x, y}) std::cout << "┌";
            else if (x == position.X+size.X-1 && y == position.Y) std::cout << "┐";
            else if (x == position.X && y == position.Y+size.Y-1) std::cout << "└";
            else if (x == position.X+size.X-1 && y == position.Y+size.Y-1) std::cout << "┘";
            else if (x == position.X || x == position.X+size.X-1) std::cout << "│";
            else if (y == position.Y || y == position.Y+size.Y-1) std::cout << "─";
            else std::cout << " ";
        console->setBackgroundColor(BLACK);
        console->setTextColor(WHITE);
        std::cout << std::endl;
    }
}

void befry::CanvasItem::set_position(Vector2 pos)
{
    position = pos;
}
void befry::CanvasItem::resize(Vector2 res)
{
    size = res;
}
void befry::CanvasItem::set_bg_color(const short& clr)
{
    color.bg_color = clr;
}
void befry::CanvasItem::set_fg_color(const short& clr)
{
    color.fg_color = clr;
}

void befry::CanvasItem::set_borderless(const bool& value)
{
    borderless = value;
}

void befry::CanvasItem::update(conio::Console* console)
{
    draw(console);
}
