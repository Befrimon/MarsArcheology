#pragma once

#include <iostream>

#include "user_interface/canvas_item.h"
#include "core/vector2.h"

#ifndef LABEL_H
#define LABEL_H

namespace befry
{
    enum TextAlign
    {
        Center,
        North, South, East, West
    };

    class Label : public CanvasItem
    {
    protected:
        std::string content;
        TextAlign text_align;

        void draw() const override;

    public:
        Label(
            std::string_view obj_name,
            const Vector2& pos, const Vector2& res,
            std::string_view text, const TextAlign& align = Center
        );
        ~Label() override;

        void set_content(std::string_view content);

        void update() override;
    };
}

#endif
