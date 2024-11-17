#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <sys/ioctl.h>
#endif

#include <conio.h>
#include <befry_engine.h>

conio::Console console = conio::Console();
const std::string TEXTURES_PATH = (std::string)std::filesystem::current_path() + "/textures/";
const befry::Vector2 SCENE_SIZE = befry::Vector2{140, 38};

befry::Vector2 term_size()
{
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return {csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1}
#elif __linux__
    winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return {w.ws_col, w.ws_row};
#endif
}

/* Scene objects */
enum scenes{START, MAIN_MENU};
int cur_scene = START;
std::vector<befry::Scene> scenes =
{
    befry::Scene(SCENE_SIZE, &console, 10),    // Start scene
    befry::Scene(SCENE_SIZE, &console, 10)     // Main menu
};

/* Scene events */
void start()
{
    switch (console.getch())
    {
        case 'q':
            exit(0);
        case ' ':
            cur_scene = MAIN_MENU;
            break;
        default:
            break;
    }
}
void main_menu()
{
    switch (console.getch())
    {
        case 'q':
            exit(0);
        case 65:
            break;
        default:
            break;
    }
}

std::vector<void(*)()> events = {&start};

/* Main function */
int main()
{
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #else
        std::cout << "Sorry, this game can't run on your OS"
        return 0;
    #endif

    /* Init start scene */
    befry::Sprite logo = befry::Sprite(SCENE_SIZE, befry::Vector2{3, 3}, TEXTURES_PATH + "logo");
    befry::Sprite sublogo = befry::Sprite(SCENE_SIZE, befry::Vector2{10, 12}, TEXTURES_PATH + "sublogo");
    befry::Label hint = befry::Label(SCENE_SIZE, befry::Vector2{55, 30}, befry::Vector2{30, 1}, "Press Space to continue...");
    scenes[START].add_children({&logo, &sublogo, &hint});

    /* Init main menu */
    std::vector<std::string> menu_btns = {" New Game", "Load Game", "Close Game"};
    for (int i = 0; i < 3; i++)
    {
        befry::Button* tmp_btn = new befry::Button(SCENE_SIZE, befry::Vector2{66, 20 + 2*i}, befry::Vector2{12, 1}, menu_btns[i]);
        tmp_btn->set_borderless(true);
        tmp_btn->set_active_fg(GREEN);
        scenes[MAIN_MENU].add_children({tmp_btn});
    }
    scenes[MAIN_MENU].add_children({&logo});

    while (true)
    {
        if (console.kbhit())
            events[cur_scene]();
        scenes[cur_scene].render(term_size());
    }
}
