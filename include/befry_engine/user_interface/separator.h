#pragma once

#include "canvas_item.h"

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
            std::string_view obj_name,
            const Vector2& pos, const int& len, const SepType& t
        );
        ~Separator() override;

        void set_bg_color(const short& clr) override;
        void set_fg_color(const short& clr) override;

        void update() override;
    };
}

#endif
