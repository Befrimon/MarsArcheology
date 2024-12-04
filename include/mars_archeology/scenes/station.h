#pragma once

#include <befry_engine.h>

#ifndef STATION_H
#define STATION_H

namespace march
{
    class Station : public befry::Scene
    {

    public:
        Station();
        ~Station() override;

        int render() override;
        void event() override;
    };
}

#endif
