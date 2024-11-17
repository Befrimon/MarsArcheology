#include "conio.h"

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

conio::Console::Console() : background_color(40) {}
conio::Console::~Console()
{
    printf("\033[m");
}


void conio::Console::clearLine()
{
    std::cout << "\033[K";
}
void conio::Console::insertLine()
{
    std::cout << "\x1b[1L";
}
void conio::Console::deleteLine()
{
    std::cout << "\033[1M";
}

void conio::Console::setCursorPosition(int x, int y)
{
    std::cout << "\033[" << y << ";" << x << "f";
}
void conio::Console::clearScreen()
{
    std::cout << "\033[" << background_color << "m\033[2J\033[1;1f";
}

void conio::Console::setBackgroundColor(int color)
{
    background_color = (color % 16) + 40;
}

void conio::Console::setTextColor(short color)
{
    if (color >= 0 && color < 16)
        std::cout << "\033[0;" << 30+color << ";" << background_color << "m";
}

int conio::Console::setEchoMode(bool enable)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ICANON;
    if (enable)
        newt.c_lflag |= ECHO;
    else
        newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int conio::Console::ungetch(int ch)
{
    return ungetc(ch, stdin);
}
int conio::Console::getch()
{
    return setEchoMode(false);
}
int conio::Console::getche()
{
    return setEchoMode(true);
}

int conio::Console::wherexy(int &x, int &y)
{
    std::cout << "\033[6n";
    if (getch() != '\x1B') return 0;
    if (getch() != '\x5B') return 0;

    int in;
    int ly = 0, lx = 0;
    while ((in = getch()) != ';')
        ly = ly * 10 + in - '0';
    while ((in = getch()) != 'R')
        lx = lx * 10 + in - '0';

    x = lx; y = ly;
}
int conio::Console::wherex()
{
    int x = 0, y = 0;
    wherexy(x, y);
    return x;
}
int conio::Console::wherey()
{
    int x = 0, y = 0;
    wherexy(x, y);
    return y;
}

int conio::Console::kbhit()
{
    struct termios oldt, newt;
    int ch, oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

int putch(const char c)
{
    std::cout << c;
    return (int)c;
}
int cputs(const char* str)
{
    std::cout << str;
    return 0;
}

char* getpass(const char* prompt)
{
    // implementada en unistd.h
    return nullptr;
}
int gettext(int l, int t, int r, int b, void* destination)
{
    // Provide a meaningful implementation or remove the parameters if not needed.
    return 0;
}