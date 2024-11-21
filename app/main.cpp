#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <filesystem>
#include <string>

#include <conio.h>
#include <befry_engine.h>

#include "march/player.h"

/* march objects */
march::Player* plr;

/* Scenes */
std::vector<befry::Scene*> scenes;
enum Scn {HELP, START, MAIN_MENU, STATION};
int cur_scene = STATION;

/* Event functions */
void filler() { /* Use this for temp events */ }
void change_scene(short scn)
{
	befry::Scene::clear();
	cur_scene = scn;
}
void close()
{
	conio::console::clearScreen();
	exit(0);
}

/* Help scene */
void help_event()
{
	switch (befry::Input::get_key())
    {
		case KEY_Q:
            close();
        case KEY_SPACE:
			change_scene(MAIN_MENU);
            break;
        default:
            break;
    }

}
void init_help()
{
	befry::Scene* scene = new befry::Scene(&help_event);

	befry::Sprite* title = new befry::Sprite("Title", befry::Vector2{51, 2}, "help");
	// befry::Label* message = new befry

	scene->add_child({title});
	scenes.push_back(scene);
}

/* Start scene */
void start_event()
{
	switch (befry::Input::get_key())
    {
        case KEY_Q:
            close();
        case KEY_SPACE:
			change_scene(MAIN_MENU);
            break;
        default:
            break;
    }
}
void init_start()
{
	befry::Scene* scene = new befry::Scene(&start_event);

	befry::Sprite* logo			= new befry::Sprite("Logo", befry::Vector2{2, 2}, "logo");
	befry::Sprite* description 	= new befry::Sprite("Description", befry::Vector2{10, 10}, "sublogo");
	befry::Label*  hint			= new befry::Label("Hint", befry::Vector2{55, 32}, befry::Vector2{30, 1}, "Press Space to continue...");
	
	scene->add_child({logo, description, hint});
	scenes.push_back(scene);
}

/* Main menu scene */
befry::ButtonGroup* main_menu_buttons = new befry::ButtonGroup();

void main_menu_event()
{
	switch (befry::Input::get_key())
	{
		case KEY_Q:
			close();
		case KEY_H:
			change_scene(HELP);
			break;
		case KEY_SPACE:
			main_menu_buttons->get_current()->pressed();
			break;
		case KEY_UP:
			main_menu_buttons->prev();
			break;
		case KEY_DOWN:
			main_menu_buttons->next();
			break;
		default:
			break;
	}
}

void new_game()
{
	// Save file create here
	change_scene(STATION);
}
void load_game() {}

void init_main_menu()
{
	befry::Scene* scene = new befry::Scene(&main_menu_event);

	std::string text[] = {"New Game", "Load game", "Close game"};
	std::vector<void(*)()> on_click = {&new_game, &load_game, &close};
	for (int i = 0; i < 3; i++)
	{
		befry::Button* btn = new befry::Button("Btn"+std::to_string(i), befry::Vector2{60, 15 + 7*i}, befry::Vector2{20, 3}, text[i]);
		btn->set_active_fg(GREEN);
		btn->on_press_action(on_click[i]);

		main_menu_buttons->add_buttons({btn});
		scene->add_child({btn});
	}

	scene->add_child({scenes[START]->get_child("Logo")});
	scenes.push_back(scene);
}

/* Research station scene */
befry::ButtonGroup* station_buttons = new befry::ButtonGroup();

void station_event()
{
  	static_cast<befry::Label*>(scenes[STATION]->get_child("PlayerInfo"))->set_content(plr->get_player_info());
	static_cast<befry::Label*>(scenes[STATION]->get_child("ToolsInfo"))->set_content(plr->get_tools_info());

	switch(befry::Input::get_key())
	{
		case KEY_Q:
			close();
		default:
			break;
	}
}

void init_station2()
{
	befry::Scene* scene = new befry::Scene(&station_event);

	befry::Sprite* background = new befry::Sprite("Background", befry::Vector2{1, 1}, "stantion");
	befry::Label* museum = new befry::Label("Museum", befry::Vector2{1, 1}, befry::Vector2{140, 1}, "Press \'h\' to open help scene");
	befry::Label* player_info = new befry::Label("PlayerInfo", befry::Vector2{0, 1}, befry::Vector2{30, 1}, "1 level | 󰗶 10/10 | 100$");
	befry::Label* tools_info = new befry::Label("ToolsInfo", befry::Vector2{98, 1}, befry::Vector2{52, 1}, "󰜐 (1) - 100% | 󰢷 (1) - 100%  |  (1) - 100%");

	museum->set_fg_color(YELLOW);
	player_info->set_fg_color(RED);
	tools_info->set_fg_color(RED);

	scene->add_child({background, museum, player_info, tools_info});
	scenes.push_back(scene);
}

void init_station()
{
	befry::Scene* scene = new befry::Scene(&station_event);

	// befry::Label* temp = new befry::Label("Temp", befry::Vector2{6, 2}, befry::Vector2{22, 1}, "It's research station");
	befry::Sprite* tool = new befry::Sprite("ToolUpgrade", befry::Vector2{10, 6}, "tool_upgrade");
	befry::Sprite* food = new befry::Sprite("FoodAutomat", befry::Vector2{60, 2}, "food_automat");
	befry::Sprite* door = new befry::Sprite("Door", befry::Vector2{90, 6}, "door");

	std::string text[] = {"Upgrade tools", "Buy food", "Go to Mars"};
	std::vector<void(*)()> on_click = {&filler, &filler, &filler};
	for (int i = 0; i < 3; i++)
	{
		befry::Button* btn = new befry::Button("Btn"+std::to_string(i), befry::Vector2{10+45*i, 28}, befry::Vector2{30, 3}, text[i]);
		btn->set_active_fg(GREEN);
		btn->on_press_action(on_click[i]);

		station_buttons->add_buttons({btn});
		scene->add_child({btn});
	}

	scene->add_child({food, door, tool});
	scenes.push_back(scene);
}

/* List of scenes inits */
std::vector<void(*)()> scene_init = 
{
	&init_help,
	&init_start, &init_main_menu, &init_station2
};

int main()
{
	/* Set config vars */
	befry::Config::set_texture_path((std::string)std::filesystem::current_path() + "/textures/");
	befry::Config::set_scene_size(befry::Vector2{140, 40});
	befry::Config::set_scene_fps(12);

	/* Prepare console */
	conio::console::clearScreen();
	conio::console::hideCursor();

	/* Init all scenes */
	befry::Scene::clear();
	for (auto func : scene_init)
		func();

	/* Init march objects */
	plr = new march::Player();

	/* Main loop */
    while (true)
    {
		conio::console::setCursorPosition(1, 1);
        if (conio::console::kbhit())
            scenes[cur_scene]->event();

		befry::Vector2 term_size = befry::Vector2{0, 0};
		conio::console::getTerminalSize(term_size.X, term_size.Y);
        scenes[cur_scene]->render(term_size);
    }
}
