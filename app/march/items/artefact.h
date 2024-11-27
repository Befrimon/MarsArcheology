#pragma once

#include "../equip.h"

#ifndef ARTEFACT_H
#define ARTEFACT_H

namespace march
{
    class Artefact
    {
    protected:
        ToolType good_tool;
        int texture_seed;
        double fragility;

    public:
        Artefact() = default;
        virtual ~Artefact();

        virtual std::string gen_texture() = 0;
    };
}

#endif
