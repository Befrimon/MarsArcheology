#pragma once

#include <string>

#ifndef EQUIP_H
#define EQUIP_H

namespace march
{
    struct Tool
    {
        std::string name;

        befry::CurMax<int> durability;
        int level;
    };

    struct Suit
    {
        std::string name;

        befry::CurMax<double> oxygen;
        int min_temp;
        int level;
    };
}

#endif
