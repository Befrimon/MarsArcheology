#include "core/input.h"

#include <conio.h>

int befry::Input::get_key()
{
    if (!conio::console::kbhit()) return 0;
    int cmd = conio::console::getch();

    if (cmd == 27)
        return conio::console::getch() + conio::console::getch();

    return cmd;
}
