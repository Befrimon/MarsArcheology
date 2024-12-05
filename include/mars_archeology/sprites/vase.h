#pragma once

#include <befry_engine.h>

#ifndef VASE_H
#define VASE_H

namespace march
{
    class Vase : public befry::Sprite
    {
    protected:
        std::string pattern;

        void draw() const override;

    public:
        Vase(std::string_view obj_name, befry::Vector2 pos);
        ~Vase() override;

        void set_texture(std::string_view tex) override;
    };
}

#endif
