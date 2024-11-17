#pragma once

#include <iostream>
#include <conio.h>
#include "game_object.h"
#include "utility/vector2.h"

#ifndef BUTTON_H
#define BUTTON_H

namespace befry
{
    class Button : public GameObject
    {
 	protected:
        const Scene* parent;

        Vector2 position{};
        Vector2 size{};
        std::string text;
        short color;
        bool disabled;

   private:
   		void draw(Console* console) const;

   public:
        Button(const Scene& root,
            const Vector2& pos,const Vector2& size,
            const std::string& content, const short& clr = WHITE
        );
        ~Button();

        void set_text(std::string content);
        void pressed();
        void update(Console* console);
    };
}

#endif
