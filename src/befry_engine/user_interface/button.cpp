#include "game_object.h"
#include "user_interface/button.h"

#include "utility/vector2.h"
#include "scene.h"

befry::Button::Button(const Scene& root,
                      const Vector2& pos, const Vector2& size,
                      const std::string& content, const short& clr
): GameObject(root)
{
    parent = &root;
    position = pos;
    this->size = size;
    text = content;
    color = clr;
}
befry::Button::~Button() = default;

void befry::Button::draw(conio::Console* console) const
{

    std::string tmp;
    for (int y = position.Y; y < position.Y + size.Y && y <= parent->rect().Y; y++)
    {
        console->setCursorPosition(position.X, y);
        console->setTextColor(color);
        for (int x = position.X; x < position.X + size.X && x <= parent->rect().X; x++)
            if (position == Vector2{x, y}) std::cout << "┌";
            else if (x == position.X+size.X-1 && y == position.Y) std::cout << "┐";
            else if (x == position.X && y == position.Y+size.Y-1) std::cout << "└";
            else if (x == position.X+size.X-1 && y == position.Y+size.Y-1) std::cout << "┘";
            else if (x == position.X || x == position.X+size.X-1) std::cout << "│";
            else if (y == position.Y || y == position.Y+size.Y-1) std::cout << "─";
            else std::cout << " ";
        console->setTextColor(WHITE);
        std::cout << std::endl;
    }
}

void befry::Button::update(conio::Console* console) {
    draw(console);
}