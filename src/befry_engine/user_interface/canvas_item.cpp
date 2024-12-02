#include "user_interface/canvas_item.h"

#include <string_view>

befry::CanvasItem::CanvasItem(
    const std::string_view obj_name,
    const Vector2 &pos, const Vector2 &res
): GameObject(obj_name) {}


std::string_view befry::CanvasItem::get_name() const
{
    return name;
}

void befry::CanvasItem::set_position(const Vector2 &pos)
{
    position = pos;
}


