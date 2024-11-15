#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <conio.h>

#ifdef _WIN32 || _WIN64
#include <windows.h>
#elif __linux__
#include <sys/ioctl.h>
#endif

#include "game_engine/scene.h"
#include "game_engine/utility/key_listener.h"
#include "game_engine/utility/vector2.h"

befry::key_listener klis = befry::key_listener(1e7 / 60);

befry::Vector2 term_size()
{
#ifdef _WIN32 || _WIN64
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return {csbi.srWindow.Right - csbi.srWindow.Left + 1, csbi.srWindow.Bottom - csbi.srWindow.Top + 1}
#elif __linux__
    winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return {w.ws_col, w.ws_row};
#else
    std::cout << "Sorry, this game can't run on your OS"
    exit(0);/home/gdev
#endif
}

int main()
{
#ifdef _WIN32 || _WIN64
system("cls");
#elif __linux__
system("clear");
#endif

    term_size();
    befry::Scene start = befry::Scene(befry::Vector2{140, 38}, 10);

    befry::Sprite logo = befry::Sprite(start, befry::Vector2{2, 3}, "logo");
    befry::Sprite sublogo = befry::Sprite(start, befry::Vector2{10, 12}, "sublogo");

    // befry::Sprite test = befry::Sprite(start, befry::Vector2{20, 20}, "default", befry::Red);

    start.addSprite({&logo, &sublogo});

    while (true)
    {
        // if (_kbhit) return 0;
        start.render(term_size());
    }

    return 0;
}
