#pragma once

#include <befry_engine.h>

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

namespace march
{
    class MainMenu : public befry::Scene
    {
    private:
        befry::ButtonGroup buttons;

    public:
        MainMenu();
        ~MainMenu() override;

        int render() override;
        void event() override;
    };
}

#endif
