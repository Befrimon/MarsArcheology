#pragma once

#include <befry_engine.h>
#include "expeditions/expedition.h"

#ifndef PLANET_H
#define PLANET_H

namespace march
{
    enum TYPE {WASTELAND};

    class Planet : public befry::Scene
    {
    protected:
        std::shared_ptr<Expedition> exp_type;

        void update_map();

    public:
        Planet();
        ~Planet() override;

        int render() override;
        void event() override;

        void start_expedition(TYPE type);
    };
}

#endif
