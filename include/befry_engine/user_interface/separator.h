#pragma once

#include "user_interface/canvas_item.h"

#ifndef SEPARATOR_H
#define SEPARATOR_H

namespace befry
{
    enum SepType {HORIZONTAL, VERTICAL};

    class Separator : public CanvasItem
    {
    protected:
        const SepType type;
        const int length;
        void draw() const override;

    public:
        Separator(
            const std::string& obj_name,
            const Vector2& pos, const int& len, const SepType& t
        );
        ~Separator() override;
    };
}

#endif
