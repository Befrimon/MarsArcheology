#include "user_interface/canvas_item.h"
#include "user_interface/label.h"

#include "core/vector2.h"
#include "core/scene.h"

#include <conio.h>
#include <string_view>
#include <sstream>

befry::Label::Label(
    std::string_view obj_name,
    const Vector2 &pos, const Vector2 &res,
    std::string_view text, const TextAlign& align
): CanvasItem(obj_name, pos, res)
{
    content = text;
    text_align = align;
}
befry::Label::~Label() = default;

void befry::Label::draw() const
{
    /* Split by lines */
    std::vector<std::string> lines;
    std::stringstream ss(content);
    std::string line;
    while (!ss.eof())
    {
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

void befry::Label::set_content(std::string_view text)
{
    content = text;
}

void befry::Label::update()
{
    draw();
}

