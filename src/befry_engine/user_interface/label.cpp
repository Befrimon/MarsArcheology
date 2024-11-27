#include "user_interface/canvas_item.h"
#include "user_interface/label.h"

#include "core/vector2.h"
#include "core/scene.h"

#include <conio.h>
#include <sstream>

befry::Label::Label(
    const std::string& obj_name,
    const befry::Vector2 &pos, const befry::Vector2 &res,
    const std::string& text, const TextAlign& align
): CanvasItem(obj_name, pos, res)
{
    borderless = true;
    content = text;
    text_align = align;
}
befry::Label::~Label() = default;

void befry::Label::draw() const
{
    CanvasItem::draw();

    /* Split by lines */
    std::vector<std::string> lines;
    std::stringstream ss(content);
    std::string line;
    while (!ss.eof()) {
        std::getline(ss, line, '\n');
        lines.push_back(line);
    }

    /* Print */
    for (int y = 0; y < lines.size(); y++)
    {
        int pos_x = 0, pos_y = 0;
        switch (text_align)
        {
        case Center:
            pos_x = (size.X - static_cast<int>(lines[y].length())) / 2;
            pos_y = (size.Y - static_cast<int>(lines.size())) / 2 + y;
            break;
        case North:
            pos_x = (size.X - static_cast<int>(lines[y].length())) / 2;
            pos_y = y;
            break;
        case South:
            pos_x = (size.X - static_cast<int>(lines[y].length())) / 2;
            pos_y = size.Y - static_cast<int>(lines.size()) + y;
            break;
        case West:
            pos_x = 0;
            pos_y = (size.Y - static_cast<int>(lines.size())) / 2 + y;
            break;
        case East:
            pos_x = size.X - static_cast<int>(lines[y].length());
            pos_y = (size.Y - static_cast<int>(lines.size())) / 2 + y;
            break;
        default:
            pos_x = 0;
            pos_y = y;
            break;
        }

        conio::console::setCursorPosition(position.X+pos_x, position.Y+pos_y);
        conio::console::setBackgroundColor(color.bg_color);
        conio::console::setTextColor(color.fg_color);
        std::cout << lines[y];
        conio::console::setBackgroundColor(RESET);
        conio::console::setTextColor(RESET);
        std::cout << std::endl;
    }
}

void befry::Label::set_content(const std::string& text)
{
    content = text;
}

void befry::Label::update()
{
    draw();
}
