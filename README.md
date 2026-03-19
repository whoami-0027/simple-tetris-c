# simple-tetris-c
## Description:

A (very) simple console-based tetris clone made entirely in C.

At the moment it is only available on Windows.

## Configuring and Building:
### Configuring:

Install these dependencies and set PATH if needed:
- Clang 19.1.7 (download [here](https://github.com/brechtsanders/winlibs_mingw/releases/download/14.2.0posix-19.1.7-12.0.0-msvcrt-r3/winlibs-x86_64-posix-seh-gcc-14.2.0-llvm-19.1.7-mingw-w64msvcrt-12.0.0-r3.7z))
- CMake 4.2.3

Clone this repository, go into its root directory, then configure with:

    cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_C_COMPILER=clang

Additionally you can add `-DCMAKE_EXPORT_COMPILE_COMMANDS` to generate `compile_commands.json` used by `clangd` (which I do)

### Building:

After configuring, you can build with:

    cmake --build build

This will generate `game.exe` in `build` directory.

## How to play:

- Moving left/right: `A/D`
- Rotating (90 degree, only clockwise): `R`
- Instantly drop: `S`
- Quit: `Q`
- Manually get a new block (and delete the current one): `N`(*)

(*) You can enable/disable this feature by uncommenting/commenting this line in `game.h`:

    #define GAME_RULE_ENABLE_RANDOM_KEY

and then rebuild the project.

## Additional information:

- You can change the speed by modifying `GAME_DISTANCE_GAIN_RATE` in `game.h`. Default is set to `3.5`.
- You can also change the size of playfield by modifying `GAME_PLAYFIELD_W` and `GAME_PLAYFIELD_H`. Default are `10` and `24` respectively, but I don't recommend changing it to anything below these values.
- And don't forget to rebuild after making these changes :D

## License:

This whole project is under Public Domain, so do whatever you want with it!

That's all! :D