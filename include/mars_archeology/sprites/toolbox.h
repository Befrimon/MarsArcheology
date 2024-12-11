#pragma once

#include <befry_engine.h>

#ifndef TOOLBOX_H
#define TOOLBOX_H

namespace march
{
    class Toolbox : public befry::Label
    {
    protected:
        void draw() const override;
    public:
        Toolbox(std::string_view obj_name, const befry::Vector2& pos);
        ~Toolbox() override;

        void update() override;
    };
}

#endif
