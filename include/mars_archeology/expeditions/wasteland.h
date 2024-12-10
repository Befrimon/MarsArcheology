#pragma once

#include "expedition.h"

#ifndef WASTELAND_H
#define WASTELAND_H

namespace march
{
    class Wasteland : public Expedition
    {
    protected:
        void effect() override;

    public:
        Wasteland();
        ~Wasteland() override;

        void explore(befry::Vector2 coord) override;
        std::string get_tile(befry::Vector2 coord) override;
    };
}

#endif
