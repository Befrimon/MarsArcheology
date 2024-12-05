#include <befry_engine.h>
#include <conio.h>

#include "scenes/main_menu.h"
#include "loop.h"

/* On click events */
void new_game()
{
    befry::Scene::clear();
    march::GameLoop::set_active_scene(march::STATION);
}
void load_game() {}
void close()
{
    conio::console::clearScreen();
    exit(0);
}

march::MainMenu::MainMenu()
{
    children.push_back(std::make_shared<befry::Sprite>("Logo", befry::Vector2{2, 2}, "logo"));
    children.push_back(std::make_shared<befry::Sprite>("Description", befry::Vector2{10, 10}, "sublogo"));

    std::string text[] = {"New Game", "Load game", "Close game"};
    std::vector on_click = {&new_game, &load_game, &close};
    for (int i = 0; i < 3; i++)
    {
        buttons.add_button("Btn"+std::to_string(i), befry::Vector2{60, 20 + 7*i}, befry::Vector2{20, 3}, text[i]);
        buttons.get_by_id(i)->set_active_fg(GREEN);
        buttons.get_by_id(i)->connect(on_click[i]);
    }
    buttons.get_current()->set_selected(true);
}
march::MainMenu::~MainMenu() = default;

int march::MainMenu::render()
{
    if (Scene::render() == -1)
        return -1;

    for (std::shared_ptr<befry::GameObject> obj : children)
        obj->update();
    for (int i = 0; i < buttons.length(); i++)
        buttons.get_by_id(i)->update();

    return 0;
}

void march::MainMenu::event()
{
    if (conio::console::kbhit()) switch (befry::Input::get_key())
    {
        case KEY_Q:
            exit(0);
        case KEY_H:
            break;
        case KEY_SPACE:
            buttons.get_current()->click();
            break;
        case KEY_UP:
            buttons.prev();
            break;
        case KEY_DOWN:
            buttons.next();
            break;
        default:
            break;
    }
}

