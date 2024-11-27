#include <iostream>
#include <string>
#include <filesystem>

#include <conio.h>
#include <befry_engine.h>
#include <cassert>

#include "march/player.h"
#include "march/tool_box.h"
#include "march/expedition/map.h"

/* march objects */
march::Player* plr;

/* Scenes */
std::vector<befry::Scene*> scenes;
enum Scn {HELP, MAIN_MENU, STATION, SHOP, MUSEUM, EXPEDITION};
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
	if (conio::console::kbhit()) switch (befry::Input::get_key())
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

/* Main menu scene */
befry::ButtonGroup* main_menu_buttons = new befry::ButtonGroup();
void new_game()
{
	// Save file create here
	change_scene(STATION);
}
void load_game() {}
void main_menu_event()
{
  	if (conio::console::kbhit()) switch (befry::Input::get_key())
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
void init_main_menu()
{
	befry::Scene* scene = new befry::Scene(&main_menu_event);

	befry::Sprite* logo			= new befry::Sprite("Logo", befry::Vector2{2, 2}, "logo");
	befry::Sprite* description 	= new befry::Sprite("Description", befry::Vector2{10, 10}, "sublogo");

	std::string text[] = {"New Game", "Load game", "Close game"};
	std::vector<void(*)()> on_click = {&new_game, &load_game, &close};
	for (int i = 0; i < 3; i++)
	{
		befry::Button* btn = new befry::Button("Btn"+std::to_string(i), befry::Vector2{60, 20 + 7*i}, befry::Vector2{20, 3}, text[i]);
		btn->set_active_fg(GREEN);
		btn->on_press_action(on_click[i]);

		main_menu_buttons->add_buttons({btn});
		scene->add_child({btn});
	}

	scene->add_child({logo, description});
	scenes.push_back(scene);
}

/* Research station scene */
befry::ButtonGroup* station_buttons = new befry::ButtonGroup();
void station_event()
{
  	dynamic_cast<befry::Label*>(scenes[STATION]->get_child("PlayerInfo"))->set_content(plr->get_player_info());
	dynamic_cast<befry::Label*>(scenes[STATION]->get_child("ToolsInfo"))->set_content(plr->get_tools_info());

 	if (conio::console::kbhit()) switch(befry::Input::get_key())
	{
	case KEY_Q:
		close();
   	case KEY_H:
  		break;
 	case KEY_UP:
 		change_scene(EXPEDITION);
 		break;
   	case KEY_RIGHT:
    	change_scene(SHOP);
  		break;
   	case KEY_LEFT:
    	change_scene(MUSEUM);
  		break;
	default:
		break;
	}
}
void init_station()
{
	befry::Scene* scene = new befry::Scene(&station_event);

	befry::Sprite* background = new befry::Sprite("Background", befry::Vector2{1, 1}, "stantion");
	befry::Label* hint = new befry::Label("Hint", befry::Vector2{1, 1}, befry::Vector2{140, 1}, "Press \'h\' to open help");
	befry::Label* player_info = new befry::Label("PlayerInfo", befry::Vector2{1, 1}, befry::Vector2{143, 1}, "1 level | 󰗶 10/10 | 100$", befry::West);
	befry::Label* tools_info = new befry::Label("ToolsInfo", befry::Vector2{1, 1}, befry::Vector2{148, 1}, "󰜐 (1) - 100% | 󰢷 (1) - 100%  |  (1) - 100%", befry::East);
	befry::Label* control_info = new befry::Label("ControlsInfo", befry::Vector2{1, 40}, befry::Vector2{152, 1}, " Museum |  New expedition  | Shop ");

	hint->set_fg_color(YELLOW);
	player_info->set_fg_color(RED);
	tools_info->set_fg_color(RED);

	scene->add_child({background, hint, player_info, tools_info, control_info});
	scenes.push_back(scene);
}

/* Shop scene */
void shop_event()
{
	if (conio::console::kbhit()) switch(befry::Input::get_key())
	{
	case KEY_Q:
		close();
   	case KEY_H:
  		break;
   	case KEY_RIGHT:
  		break;
   	case KEY_LEFT:
  		break;
    case KEY_DOWN:
  		change_scene(STATION);
    	break;
	default:
		break;
	}
}
void init_shop()
{
	befry::Scene* scene = new befry::Scene(&shop_event);

	befry::Sprite* background = new befry::Sprite("Background", befry::Vector2{1, 1}, "shop");
	befry::Label* control_info = new befry::Label("ControlsInfo", befry::Vector2{1, 40}, befry::Vector2{140, 1}, " Back to hall ");
	befry::Label* hint = dynamic_cast<befry::Label*>(scenes[STATION]->get_child("Hint"));

	scene->add_child({background, hint, control_info});
	scenes.push_back(scene);
}

/* Museum scene */
void museum_event()
{
	if (conio::console::kbhit()) switch(befry::Input::get_key())
	{
	case KEY_Q:
		close();
   	case KEY_H:
  		break;
   	case KEY_RIGHT:
  		break;
   	case KEY_LEFT:
  		break;
    case KEY_DOWN:
  		change_scene(STATION);
    	break;
	default:
		break;
	}
}
void init_museum()
{
	befry::Scene* scene = new befry::Scene(&museum_event);

  	/* Just example art */
 	befry::Sprite* art = new befry::Sprite("ArtObject", befry::Vector2{58, 14}, "art_empty");
 	befry::Sprite* slab = new befry::Sprite("Slab", befry::Vector2{50, 30}, "museum_slab");

	befry::Label* control_info = new befry::Label("ControlsInfo", befry::Vector2{1, 40}, befry::Vector2{140, 1}, " Prev art |  Back to hall  | Next art ");
	befry::Label* hint = dynamic_cast<befry::Label*>(scenes[STATION]->get_child("Hint"));

 	scene->add_child({art, slab, hint, control_info});
 	scenes.push_back(scene);
}

/* Game scene */
void expedition_event()
{
	if (conio::console::kbhit()) switch(befry::Input::get_key())
	{
	case KEY_Q:
		close();
	case KEY_H:
		break;
	case KEY_RIGHT:
		break;
	case KEY_LEFT:
		break;
	case KEY_DOWN:
		break;
	default:
		break;
	}
}
void init_expedition()
{
	befry::Scene* scene = new befry::Scene(&museum_event);

	befry::Separator* fst_sep = new befry::Separator("FirstSeparator", befry::Vector2{1, 31}, 78, befry::HORIZONTAL);
	befry::Separator* scn_sep = new befry::Separator("SecondSeparator", befry::Vector2{79, 1}, 40, befry::VERTICAL);
	befry::Separator* thr_sep = new befry::Separator("ThirdSeparator", befry::Vector2{80, 16}, 61, befry::HORIZONTAL);
	march::Map* big_map = new march::Map("MainMap", befry::Vector2{10, 1}, march::GLOBAL, 30);
	march::Map* mini_map = new march::Map("MiniMap", befry::Vector2{95, 1}, march::MINI, 15);

	befry::Label* ter_info = new befry::Label(
		"TerrainInfo",
		befry::Vector2{1, 32}, befry::Vector2{78, 3},
		" Temp -15°C ▼\n Time 6:00 AM\n󱐟 Food 99 days", befry::West
	);
/*
	for (int i = 0; i < 3; i++)
	{
		march::Suit* empty = new march::Suit{};
		march::ToolBox* tmp = new march::ToolBox("ToolBox" + std::to_string(i), befry::Vector2{80, 16}, plr->get_tool(i), empty);
		scene->add_child({tmp});
	}
	*/
	march::Tool* empty = new march::Tool{"Empty", "", 0, 0, 0, 0};
	march::ToolBox* suit_box = new march::ToolBox("ToolBox4", befry::Vector2{80, 16}, empty, plr->get_suit());

	scene->add_child({
		fst_sep, scn_sep, thr_sep, big_map, mini_map,
		ter_info, suit_box
	});
	scenes.push_back(scene);
}

/* List of scenes inits */
std::vector scene_init =
{
	&init_help,
	&init_main_menu, &init_station, &init_shop, &init_museum,
	&init_expedition
};

[[noreturn]] int main()
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
	for (const auto func : scene_init)
		func();

	/* Init march objects */
	plr = new march::Player();

	/* Main loop */
    while (true)
    {
		conio::console::setCursorPosition(1, 1);
   		scenes[cur_scene]->event();

		befry::Vector2 term_size = befry::Vector2{0, 0};
		conio::console::getTerminalSize(term_size.X, term_size.Y);
        scenes[cur_scene]->render(term_size);
    }
}
