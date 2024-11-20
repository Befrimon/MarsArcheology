#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <filesystem>
#include <sys/ioctl.h>

#include <conio.h>
#include <befry_engine.h>

/* Consts */
const std::string TEXTURES_PATH = (std::string)std::filesystem::current_path() + "/textures/";
const befry::Vector2 SCENE_SIZE = befry::Vector2{140, 38};
const int FPS = 12;

/* Functions */
befry::Vector2 term_size()
{
	winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return {w.ws_col, w.ws_row};
}

/* Scenes */
std::vector<befry::Scene*> scenes;
enum scenes{START, MAIN_MENU, STATION};
int cur_scene = START;

/* Event functions */
void filler() {}
void close()
{
	conio::console->clearScreen();
	exit(0);
}

/* Start scene */
void start_event()
{
	switch (befry::Input::get_key())
    {
        case KEY_Q:
            close();
        case KEY_SPACE:
			conio::console->clearScreen();
			cur_scene = MAIN_MENU;
            break;
        default:
            break;
    }
}
void init_start()
{
	befry::Scene* scene = new befry::Scene(SCENE_SIZE, &start_event, FPS);

	befry::Sprite* logo			= new befry::Sprite("Logo", befry::Vector2{2, 2}, TEXTURES_PATH+"logo");
	befry::Sprite* description 	= new befry::Sprite("Description", befry::Vector2{10, 10}, TEXTURES_PATH+"sublogo");
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
	conio::console->clearScreen();
	cur_scene = STATION;
}

void init_main_menu()
{
	befry::Scene* scene = new befry::Scene(SCENE_SIZE, &main_menu_event, FPS);

	std::string text[] = {"New Game", "Load game", "Close game"};
	std::vector<void(*)()> on_click = {&new_game, &filler, &close};
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
void station_event()
{
	switch(befry::Input::get_key())
	{
		case KEY_Q:
			close();
		default:
			break;
	}
}

void init_station()
{
	befry::Scene* scene = new befry::Scene(SCENE_SIZE, &station_event, FPS);

	befry::Label* temp = new befry::Label("Temp", befry::Vector2{6, 2}, befry::Vector2{22, 1}, "It's research station");

	scene->add_child({temp});
	scenes.push_back(scene);
}

/* List of scenes inits */
std::vector<void(*)()> scene_init = 
{
	&init_start, &init_main_menu, &init_station
};

/* Mainloop */
int main()
{
	conio::console->clearScreen();
	conio::console->hideCursor();

	for (auto func : scene_init)
		func();

    while (true)
    {
		conio::console->setCursorPosition(1, 1);
        if (conio::console->kbhit())
            scenes[cur_scene]->event();
        scenes[cur_scene]->render(term_size());
    }
}
