#include "user_interface/canvas_item.h"
#include "user_interface/label.h"

#include "core/vector2.h"
#include "core/scene.h"

#include <conio.h>

befry::Label::Label(
    const Vector2& root_size,
    const befry::Vector2 &pos, const befry::Vector2 &res,
    const std::string& text
): CanvasItem(root_size, pos, res)
{
    borderless = true;
    content = text;
}
befry::Label::~Label() = default;

void befry::Label::draw(conio::Console* console)
{
    CanvasItem::draw(console);

    console->setCursorPosition(position.X+1, position.Y + size.Y / 2);
    console->setBackgroundColor(color.bg_color);
    console->setTextColor(color.fg_color);
    for (int i = 0; i < content.length() && i < size.X-2; i++)
        std::cout << content[i];
    console->setBackgroundColor(BLACK);
    console->setTextColor(WHITE);
    std::cout << std::endl;
}

void befry::Label::set_content(const std::string& text)
{
    content = text;
}

void befry::Label::update(conio::Console *console)
{
    draw(console);
}
