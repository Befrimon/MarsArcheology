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
        North, South, East, West,
        //NorthEast, NorthWest, SouthEast, SouthWest
    };

    class Label : public CanvasItem
    {
 	protected:
        std::string content;
        TextAlign text_align;

        void draw() const override;

    public:
        Label(
            const std::string& obj_name,
            const Vector2& pos,const Vector2& res,
            const std::string& text, const TextAlign& align = Center
        );
        ~Label() override;

        void set_content(const std::string& content);

        void update() override;
    };
}

#endif
