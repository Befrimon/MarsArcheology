#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <filesystem>
#include <conio.h>z

#ifdef _WIN32 || _WIN64
#include <windows.h>
#elif __linux__
#include <sys/ioctl.h>
#endif

#include <scene.h>
#include <utility/vector2.h>

Console console = Console();
const std::string TEXTURES_PATH = (std::string)std::filesystem::current_path() + "/textures/";

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
#endif
}

int main()
{
    #ifdef _WIN32 || _WIN64
        system("cls");
    #elif __linux__
        system("clear");
    #else
        std::cout << "Sorry, this game can't run on your OS"
        return 0;
    #endif

    term_size();
    befry::Scene start = befry::Scene(befry::Vector2{140, 38}, &console, 24);

    befry::Sprite logo = befry::Sprite(start, befry::Vector2{2, 3}, TEXTURES_PATH + "logo");
    befry::Sprite sublogo = befry::Sprite(start, befry::Vector2{10, 12}, TEXTURES_PATH + "sublogo");
    befry::Sprite test = befry::Sprite(start, befry::Vector2{5, 5});

    start.addSprite({&logo, &sublogo, &test});

    while (true)
    {
        if (console.kbhit())
            switch (console.getch())
            {
                case 'q': return 0;
                default: break;
            }
        start.render(term_size());
    }
}
