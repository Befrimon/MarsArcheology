# Mars Archeology
*Game on C++ for ITMO GameDev practice. Here I use my own engine (link appears later) for console games.*

## Installation

The first stable versions of the game will appear on the releases page

## Contributing
The requirements are:
- CMake 3.14 or better.
- A C++17 compatible compiler
- My fork of [conio.h](https://github.com/Befrimon/conio.h) lib
- BefryEngine (now combined with game)
- Git

If you find some bug (in the engine or in the game), then open issue with a description of the problem

### Download and build
```bash
git clone https://github.com/Befrimon/MarsArcheology.git
cd MarsArcheology
cmake -S . -B build
cmake --build build
```
