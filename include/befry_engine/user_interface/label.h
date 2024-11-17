#pragma once

#include <iostream>
#include <conio.h>

#include "user_interface/canvas_item.h"
#include "core/vector2.h"

#ifndef LABEL_H
#define LABEL_H

namespace befry
{
    class Label : public CanvasItem
    {
 	protected:
        std::string content;

        void draw(conio::Console* console);

    public:
        Label(
            const Vector2& root_size,
            const Vector2& pos,const Vector2& res,
            const std::string& text
        );
        ~Label();

        void set_content(const std::string& content);

        void update(conio::Console* console);
    };
}

#endif
