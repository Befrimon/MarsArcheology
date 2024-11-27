#include "expedition.h"


march::Expedition::Expedition(Player* plr, ExpType t)
{
    player_ptr = plr;
    type = t;
    switch (type)
    {
        case WASTELAND:

        default:
            break;
    }
}
march::Expedition::~Expedition() = default;

/* Generators */
void march::Expedition::wasteland()
{
    name = "Chryse Plantia";
    temperature = static_cast<double>(-750 + std::rand() % 310) / 100;
    level = 1;
    time = 600;
}
