#pragma once

#ifndef COLORS_H
#define COLORS_H

#define RESET       "\033[0m"               /* Default */
#define BLACK       "\033[30m"              /* Black */
#define RED         "\033[31m"              /* Red */
#define GREEN       "\033[32m"              /* Green */
#define YELLOW      "\033[33m"              /* Yellow */
#define BLUE        "\033[34m"              /* Blue */
#define MAGENTA     "\033[35m"              /* Magenta */
#define CYAN        "\033[36m"              /* Cyan */
#define WHITE       "\033[37m"              /* White */

namespace befry
{
    enum COLORS {Default, Black, Red, Green, Yellow, Blue, Magenta, Cyan, White};

    inline std::string to_string(const COLORS& clr) {
        switch (clr) {
            case Default:   return RESET;
            case Black:     return BLACK;
            case Red:       return RED;
            case Green:     return GREEN;
            case Yellow:    return YELLOW;
            case Blue:      return BLUE;
            case Magenta:   return  MAGENTA;
            case Cyan:      return CYAN;
            case White:     return WHITE;
            default:        return RESET;
        }
    }
}

#endif
