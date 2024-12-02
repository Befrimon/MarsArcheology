#pragma once

#include "../../conio/conio.h"
#include "canvas_item.h"
#include "core/vector2.h"

#ifndef BUTTON_H
#define BUTTON_H

namespace befry
{
    class Button : public CanvasItem
    {
 	protected:
        std::string content;
        CanvasColor active_color = CanvasColor{BLACK, GREEN};
        CanvasColor disabled_color = CanvasColor{BLACK, GRAY};
        bool selected;
        bool disabled;
        void (*event)();

        void draw() const override;

   public:
        Button(std::string_view obj_name,
            const Vector2& pos,const Vector2& size,
            std::string_view text = ""
        );
        ~Button() override;

        std::string_view get_name() const override;

        void set_content(std::string_view text);
        void set_selected(const bool& value);
        void set_disabled(const bool& value);

        void set_bg_color(const short& clr) override;
        void set_fg_color(const short& clr) override;
        void set_disabled_bg(const short& clr);
        void set_disabled_fg(const short& clr);
        void set_active_bg(const short& clr);
        void set_active_fg(const short& clr);

        void connect(void (*func)());
        void click();

        void update() override;
    };
}

#endif
