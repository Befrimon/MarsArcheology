#include "user_interface/canvas_item.h"
#include "user_interface/button.h"

#include "core/vector2.h"
#include "core/scene.h"

befry::Button::Button(const Vector2& root_size,
                      const Vector2& pos, const Vector2& res,
                      const std::string& text
): befry::CanvasItem(root_size, pos, res), disabled(false), selected(false)
{
    content = text;
}
befry::Button::~Button() = default;

void befry::Button::draw(conio::Console* console)
{
    CanvasItem::draw(console);

    console->setCursorPosition(position.X+1, position.Y + size.Y / 2);
    if (disabled)
    {
        console->setBackgroundColor(disabled_color.bg_color);
        console->setTextColor(disabled_color.fg_color);
    }
    else if (selected)
    {
        console->setBackgroundColor(active_color.bg_color);
        console->setTextColor(active_color.fg_color);
    }
    else
    {
        console->setBackgroundColor(color.bg_color);
        console->setTextColor(color.fg_color);
    }
    for (int i = 0; i < content.length() && i < size.X-2; i++)
        std::cout << content[i];
    console->setBackgroundColor(BLACK);
    console->setTextColor(WHITE);
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

void befry::Button::update(conio::Console* console)
{
    draw(console);
}