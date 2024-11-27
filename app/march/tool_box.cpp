#include "tool_box.h"

march::ToolBox::ToolBox(
    const std::string &obj_name,
    const befry::Vector2 &pos,
    const Tool* t, const Suit* s
) : Label(obj_name, pos, befry::Vector2{12, 6}, "", befry::West)
{
    if (t->name == "Empty")
        delete t;
    if (s->name == "Empty")
        delete s;
    tool = t; suit = s;

    borderless = false;
}

march::ToolBox::~ToolBox() = default;

void march::ToolBox::update()
{
    if (tool != nullptr)
        set_content(
            tool->icon + "\n" +
            tool->name + " - " + std::to_string(tool->level) + " level\n" +
            "Durability " + std::to_string(tool->durability) +
            "Efficiency " + std::to_string(tool->efficiency)
        );
    else if (suit != nullptr)
        set_content(
            "\nSpacesuit - " + std::to_string(suit->level) + " level\n" +
            "Oxygen " + std::to_string(suit->oxygen) +
            "Warm coefficient " + std::to_string(suit->warm_coef)
        );
}
