#include <time.h>

#include "game.h"

time_t oldTime = 0;
time_t deltaTime = 0;
time_t timeAccumulator = 0;

int main()
{
        // Initialize the game
        if(game_func_init() != ERROR_NONE)
                return game_func_terminate();

        oldTime = clock();
        // Game loop
        // Here "timing fuzziness" method is used (from
        // https://medium.com/@tglaiel/how-to-make-your-game-run-at-60fps-24c61210fe75)
        while(!game_flag_terminated) {
                deltaTime = clock() - oldTime;
                oldTime = clock();
                timeAccumulator += deltaTime;

                while(!game_flag_terminated
                      && timeAccumulator > ( GAME_UPDATE_INTERVAL
                                             + GAME_FUZZY_TIME_INTERVAL )) {
                        game_func_getPlayerInput();
                        game_func_update();
                        game_func_draw();

                        timeAccumulator -= ( GAME_UPDATE_INTERVAL
                                             - GAME_FUZZY_TIME_INTERVAL );
                        if(timeAccumulator < 0)
                                timeAccumulator = 0;
                }
        }

        // Terminate the game
        return game_func_terminate();
}