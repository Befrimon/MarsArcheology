#pragma once

#include <string>
#include <conio.h>

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
        CanvasColor color;
        bool borderless;

        void draw(conio::Console* console) const;

    public:
        CanvasItem(
            const Vector2& root_size,
            const Vector2& pos,const Vector2& res
        );
        ~CanvasItem();

        void set_position(Vector2 pos);
        void resize(Vector2 res);
        void set_bg_color(const short& clr);
        void set_fg_color(const short& clr);

        void set_borderless(const bool& value);

        void update(conio::Console* console);
    };
}

#endif