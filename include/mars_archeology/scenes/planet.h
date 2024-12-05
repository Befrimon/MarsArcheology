#pragma once

#include <befry_engine.h>

#ifndef PLANET_H
#define PLANET_H

namespace march
{
    class Planet : public befry::Scene
    {
    public:
        Planet();
        ~Planet() override;

        int render() override;
        void event() override;
    };
}

#endif
