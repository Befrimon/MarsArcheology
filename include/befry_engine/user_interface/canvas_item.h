#pragma once

#include <string>
#include <string_view>

#include "core/game_object.h"
#include "core/vector2.h"

#ifndef CANVAS_ITEM_H
#define CANVAS_ITEM_H

namespace befry
{
    struct CanvasColor
    {
        short bg_color;
        short fg_color;
    };

    class CanvasItem : public GameObject
    {
    protected:
        Vector2 position{};
        Vector2 size{};
        CanvasColor color{};

        void draw() const override = 0;

    public:
        CanvasItem(
            std::string_view obj_name,
            const Vector2& pos, const Vector2& res
        );
        ~CanvasItem() override = default;

        std::string_view get_name() const override;

        virtual void set_position(const Vector2& pos);
        virtual void set_bg_color(const short& clr) = 0;
        virtual void set_fg_color(const short& clr) = 0;

        void update() override = 0;
    };
}

#endif
