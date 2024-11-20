#include "user_interface/canvas_item.h"
#include "core/game_object.h"
#include "core/scene.h"

#include <iostream>

befry::CanvasItem::CanvasItem(
    const std::string& obj_name,
    const befry::Vector2& pos, const befry::Vector2& res
): GameObject(obj_name)
{
    position = pos + Vector2{1, 1};
    size = res;
    color = {BLACK, WHITE};
    borderless = false;
}
befry::CanvasItem::~CanvasItem() = default;
std::string befry::CanvasItem::get_name() const { return name; }

void befry::CanvasItem::draw() const
{
    std::string tmp;
    for (int y = position.Y-1; y <= position.Y + size.Y && !borderless; y++)
    {
		conio::console->setCursorPosition(position.X-1, y);
		conio::console->setBackgroundColor(color.bg_color);
		conio::console->setTextColor(color.fg_color);
        for (int x = position.X-1; x <= position.X + size.X; x++)
            if 		(x == position.X-1 && y == position.Y-1) 			std::cout << "┌";
            else if (x == position.X+size.X && y == position.Y-1) 		std::cout << "┐";
            else if (x == position.X-1 && y == position.Y+size.Y) 		std::cout << "└";
            else if (x == position.X+size.X && y == position.Y+size.Y) 	std::cout << "┘";
            else if (x == position.X-1 || x == position.X+size.X) 		std::cout << "│";
            else if (y == position.Y-1 || y == position.Y+size.Y) 		std::cout << "─";
            else 														std::cout << " ";
		conio::console->setBackgroundColor(RESET);
		conio::console->setTextColor(WHITE);
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

void befry::CanvasItem::update()
{
    draw();
}
