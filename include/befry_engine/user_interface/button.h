#pragma once

#include <iostream>
#include <conio.h>

#include "user_interface/canvas_item.h"
#include "user_interface/label.h"
#include "core/vector2.h"

#ifndef BUTTON_H
#define BUTTON_H

namespace befry
{	
    class Button : public CanvasItem
    {
 	protected:
        std::string content;
        CanvasColor active_color;
        CanvasColor disabled_color;
        bool selected;
        bool disabled;
		callback_function on_click;	

        void draw();

   public:
        Button(const std::string& obj_name,
            const Vector2& pos,const Vector2& size,
            const std::string& text = ""
        );
        ~Button();

        void set_content(const std::string& text);
        void set_selected(const bool& value);
        void set_disabled(const bool& value);

        void set_disabled_bg(const short& clr);
        void set_disabled_fg(const short& clr);
        void set_active_bg(const short& clr);
        void set_active_fg(const short& clr);

		void on_press_action(callback_function new_func);
        void pressed();

        void update();
    };
}

#endif
