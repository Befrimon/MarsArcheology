#pragma once

#include <befry_engine.h>

#ifndef SHOP_H
#define SHOP_H

namespace march
{
    class Shop : public befry::Scene
    {
    public:
        Shop();
        ~Shop() override;

        int render() override;
        void event() override;
    };
}

#endif
