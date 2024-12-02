#pragma once

#include <befry_engine.h>

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

namespace march
{
    class MainMenu : public befry::Scene
    {
    protected:

    public:
        MainMenu();
        ~MainMenu() override;

        befry::GameObject& get_child(std::string obj_name) const override;

        void render() override;
        void event() override;
    };
}

#endif
