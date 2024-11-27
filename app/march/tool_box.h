#pragma once

#include "equip.h"

#include <befry_engine.h>

#include "player.h"

#ifndef TOOL_BOX_H
#define TOOL_BOX_H

namespace march
{
    class ToolBox : public befry::Label
    {
    protected:
        const Tool* tool;
        const Suit* suit;

    public:
        ToolBox(
            const std::string& obj_name,
            const befry::Vector2& pos,
            const Tool* t, const Suit* s
        );

        ~ToolBox() override;

        void update() override;
    };
}

#endif
