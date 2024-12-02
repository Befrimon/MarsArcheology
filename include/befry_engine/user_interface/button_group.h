#pragma once

#include <vector>

#include "user_interface/button.h"
#include "core/vector2.h"

#ifndef BUTTON_GROUP_H
#define BUTTON_GROUP_H

namespace befry
{
    class ButtonGroup
    {
    protected:
        int current;
        std::vector<Button> buttons;

    public:
        ButtonGroup();
        ~ButtonGroup();

        void add_button(
            std::string_view obj_name,
            const Vector2& pos,const Vector2& size,
            std::string_view text = ""
        );
        void set_current(int id);
        void prev();
        void next();
        Button get_current() const;
    };
}

#endif
