#include "user_interface/canvas_item.h"
#include "user_interface/label.h"

#include "core/vector2.h"
#include "core/scene.h"

#include <conio.h>

befry::Label::Label(
    const std::string& obj_name,
    const befry::Vector2 &pos, const befry::Vector2 &res,
    const std::string& text
): CanvasItem(obj_name, pos, res)
{
    borderless = true;
    content = text;
}
befry::Label::~Label() = default;

void befry::Label::draw()
{
    CanvasItem::draw();

	int start_x = 0;
	if (size.X - content.length() > 0)
		start_x = (size.X - content.length()) / 2;
	conio::console->setCursorPosition(position.X+start_x, position.Y + size.Y / 2);

	conio::console->setBackgroundColor(color.bg_color);
	conio::console->setTextColor(color.fg_color);

    for (int i = 0; i < content.length() && i < size.X; i++)
        std::cout << content[i];
    
	conio::console->setBackgroundColor(BLACK);
	conio::console->setTextColor(WHITE);
    std::cout << std::endl;
}

void befry::Label::set_content(const std::string& text)
{
    content = text;
}

void befry::Label::update()
{
    draw();
}
