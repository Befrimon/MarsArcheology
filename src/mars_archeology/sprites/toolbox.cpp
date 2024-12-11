#include "sprites/toolbox.h"

march::Toolbox::Toolbox(
    std::string_view obj_name, const befry::Vector2& pos,
) :Label(obj_name, pos, befry::Vector2{55, 4}, "", befry::West)
{}
march::Toolbox::~Toolbox() = default;

void march::Toolbox::draw() const
{
    Label::draw();
    for (int y = position.Y-1; y <= position.Y + size.Y; y++)
    {
        conio::console::setCursorPosition(position.X-1, y);
        conio::console::setBackgroundColor(color.bg_color);
        conio::console::setTextColor(color.fg_color);
        for (int x = position.X-1; x <= position.X + size.X; x++)
        {
            conio::console::setCursorPosition(x, y);
            if 		(x == position.X-1 && y == position.Y-1) 			std::cout << "┌";
            else if (x == position.X+size.X && y == position.Y-1) 		std::cout << "┐";
            else if (x == position.X-1 && y == position.Y+size.Y) 		std::cout << "└";
            else if (x == position.X+size.X && y == position.Y+size.Y) 	std::cout << "┘";
            else if (x == position.X-1 || x == position.X+size.X) 		std::cout << "│";
            else if (y == position.Y-1 || y == position.Y+size.Y) 		std::cout << "─";
        }
        conio::console::setBackgroundColor(BLACK);
        conio::console::setTextColor(RESET);
        std::cout << std::endl;
    }

}

void march::Toolbox::update()
{
    Label::update();

    content =
        name + "(" + (name == "Suit" ? "Spacesuit" : "Instrument") + ")\n" +
        "1 level (Bronze tier)\n" +
        "Durability: 100%\n" +
        "Efficiency: 0.8";
}
