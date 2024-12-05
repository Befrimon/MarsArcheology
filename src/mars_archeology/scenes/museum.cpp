#include "scenes/museum.h"

#include "loop.h"
#include "sprites/vase.h"

march::Museum::Museum()
{
    children.push_back(std::make_shared<Vase>("Empty", befry::Vector2{56, 10}));
    children.push_back(std::make_shared<befry::Sprite>("Slab", befry::Vector2{50, 30}, "museum_slab"));
    children.push_back(std::make_shared<befry::Label>("ArtCount", befry::Vector2{1, 1}, befry::Vector2{140, 1}, ""));
    children.push_back(std::make_shared<befry::Label>("ControlsInfo", befry::Vector2{1, 40}, befry::Vector2{140, 1}, " Prev art |  Back to hall  | Next art "));

    /* Example */
    arts = {"Art1", "Art2", "Art3", "Art4"};
    std::static_pointer_cast<Vase>(get_child("Empty"))->set_texture(arts[cur_art]);
}
march::Museum::~Museum() = default;


int march::Museum::render()
{
    if (Scene::render() == -1)
        return -1;

    std::shared_ptr<befry::Label> vcount = std::static_pointer_cast<befry::Label>(get_child("ArtCount"));
    vcount->set_content("Artefact: " + std::to_string(cur_art+1) + "/" + std::to_string(arts.size()));

    for (std::shared_ptr<befry::GameObject> obj : children)
        obj->update();

    return 0;
}

void march::Museum::event()
{
    if (conio::console::kbhit()) switch(befry::Input::get_key())
    {
        case KEY_Q:
            exit(0);
        case KEY_H:
            break;
        case KEY_RIGHT:
            if (cur_art >= arts.size()-1) break;
            std::static_pointer_cast<Vase>(get_child("Empty"))->set_texture(arts[cur_art+1]);
            cur_art++;
            break;
        case KEY_LEFT:
            if (cur_art <= 0) break;
            std::static_pointer_cast<Vase>(get_child("Empty"))->set_texture(arts[cur_art-1]);
            cur_art--;
            break;
        case KEY_DOWN:
            clear();
            GameLoop::set_active_scene(STATION);
            break;
        default:
            break;
    }
}

