#pragma once

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <termios.h>

#include "colors.h"

#ifndef KEY_LISTENER_H
#define KEY_LISTENER_H

namespace befry
{
    class key_listener
    {
    private:
        termios oldSettings{}, newSettings{};
        fd_set set;
        timeval tv{};

    public:
        key_listener(int tick)
        {
            tv.tv_sec = 0;
            tv.tv_usec = tick;

            tcgetattr(fileno(stdin), &oldSettings);
            newSettings = oldSettings;
            newSettings.c_lflag &= (~ICANON & ~ECHO);
            tcsetattr(fileno(stdin), TCSANOW, &newSettings);
        }
        ~key_listener()
        {
            tcsetattr(fileno(stdin), TCSANOW, &oldSettings);
        }

        char read_key()
        {
            FD_ZERO(&set);
            FD_SET(fileno(stdin), &set);

            int res = select(fileno(stdin)+1, &set, NULL, NULL, &tv);

            if (res > 0)
            {
                char c;
                read(fileno(stdin), &c, 1);
                return c;
            }
            if (res < 0)
            {
                std::cout << RED << "Key Listener error!!!" << std::endl << RESET;
                std::exit(-1);
            }
            std::cout << std::endl;
            return 0;
        }
    };
}

#endif
