#pragma once

#include <befry_engine.h>

#ifndef MUSEUM_H
#define MUSEUM_H

namespace march
{
    class Museum : public befry::Scene
    {
    protected:
        std::vector<std::string> arts;
        int cur_art = 0;

    public:
        Museum();
        ~Museum() override;

        int render() override;
        void event() override;
    };
}

#endif
