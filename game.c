#include "game.h"

#include <processenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

const bool game_blockTemplate[TYPE_COUNT][STATE_COUNT][4][4] = {
        // Type: O
        { // Rotation: Default
            {
                { 0, 0, 0, 0 },
                { 0, 1, 1, 0 },
                { 0, 1, 1, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 1
            {
                { 0, 0, 0, 0 },
                { 0, 1, 1, 0 },
                { 0, 1, 1, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 2
            {
                { 0, 0, 0, 0 },
                { 0, 1, 1, 0 },
                { 0, 1, 1, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 3
            {
                { 0, 0, 0, 0 },
                { 0, 1, 1, 0 },
                { 0, 1, 1, 0 },
                { 0, 0, 0, 0 },
            } },
        // Type: I
        { // Rotation: Default
            {
                { 0, 0, 0, 0 },
                { 1, 1, 1, 1 },
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 1
            {
                { 0, 0, 1, 0 },
                { 0, 0, 1, 0 },
                { 0, 0, 1, 0 },
                { 0, 0, 1, 0 },
            },
            // Rotation: 2
            {
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 },
                { 1, 1, 1, 1 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 3
            {
                { 0, 1, 0, 0 },
                { 0, 1, 0, 0 },
                { 0, 1, 0, 0 },
                { 0, 1, 0, 0 },
            } },
        // Type: L
        { // Rotation: Default
            {
                { 0, 0, 0, 0 },
                { 1, 0, 0, 0 },
                { 1, 1, 1, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 1
            {
                { 0, 0, 0, 0 },
                { 0, 1, 1, 0 },
                { 0, 1, 0, 0 },
                { 0, 1, 0, 0 },
            },
            // Rotation: 2
            {
                { 0, 0, 0, 0 },
                { 1, 1, 1, 0 },
                { 0, 0, 1, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 3
            {
                { 0, 0, 0, 0 },
                { 0, 1, 0, 0 },
                { 0, 1, 0, 0 },
                { 1, 1, 0, 0 },
            } },
        // Type: RL
        { // Rotation: Default
            {
                { 0, 0, 0, 0 },
                { 0, 0, 1, 0 },
                { 1, 1, 1, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 1
            {
                { 0, 0, 0, 0 },
                { 0, 1, 0, 0 },
                { 0, 1, 0, 0 },
                { 0, 1, 1, 0 },
            },
            // Rotation: 2
            {
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 },
                { 1, 1, 1, 0 },
                { 1, 0, 0, 0 },
            },
            // Rotation: 3
            {
                { 0, 0, 0, 0 },
                { 1, 1, 0, 0 },
                { 0, 1, 0, 0 },
                { 0, 1, 0, 0 },
            } },
        // Type: S
        { // Rotation: Default
            {
                { 0, 0, 0, 0 },
                { 0, 1, 1, 0 },
                { 1, 1, 0, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 1
            {
                { 0, 0, 0, 0 },
                { 0, 1, 0, 0 },
                { 0, 1, 1, 0 },
                { 0, 0, 1, 0 },
            },
            // Rotation: 2
            {
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 },
                { 0, 1, 1, 0 },
                { 1, 1, 0, 0 },
            },
            // Rotation: 3
            {
                { 0, 0, 0, 0 },
                { 1, 0, 0, 0 },
                { 1, 1, 0, 0 },
                { 0, 1, 0, 0 },
            } },
        // Type: RS
        { // Rotation: Default
            {
                { 0, 0, 0, 0 },
                { 1, 1, 0, 0 },
                { 0, 1, 1, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 1
            {
                { 0, 0, 0, 0 },
                { 0, 0, 1, 0 },
                { 0, 1, 1, 0 },
                { 0, 1, 0, 0 },
            },
            // Rotation: 2
            {
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 },
                { 1, 1, 0, 0 },
                { 0, 1, 1, 0 },
            },
            // Rotation: 3
            {
                { 0, 0, 0, 0 },
                { 0, 1, 0, 0 },
                { 1, 1, 0, 0 },
                { 1, 0, 0, 0 },
            } },
        // Type: T
        { // Rotation: Default
            {
                { 0, 0, 0, 0 },
                { 0, 1, 0, 0 },
                { 1, 1, 1, 0 },
                { 0, 0, 0, 0 },
            },
            // Rotation: 1
            {
                { 0, 0, 0, 0 },
                { 0, 1, 0, 0 },
                { 0, 1, 1, 0 },
                { 0, 1, 0, 0 },
            },
            // Rotation: 2
            {
                { 0, 0, 0, 0 },
                { 0, 0, 0, 0 },
                { 1, 1, 1, 0 },
                { 0, 1, 0, 0 },
            },
            // Rotation: 3
            {
                { 0, 0, 0, 0 },
                { 0, 1, 0, 0 },
                { 1, 1, 0, 0 },
                { 0, 1, 0, 0 },
            } },
};

bool game_flag_keyPressed_A = false;
bool game_flag_keyPressed_D = false;
bool game_flag_keyPressed_R = false;
bool game_flag_keyPressed_Q = false;
bool game_flag_keyPressed_S = false;
bool game_flag_forceTerminationRequested = true;
bool game_flag_terminated = false;
bool game_flag_blockExisting = false;
bool game_flag_enableLockDelayFrameCounter = false;
int game_lockDelayFrameCounter = 0;
int game_init_returnCode = ERROR_NONE;
int game_update_returnCode = ERROR_NONE;
int game_exitCode = ERROR_NONE;
enum cell_type game_currentBlock_type = TYPE_NONE;
enum rotation_state game_currentBlock_rotation = STATE_0;
int game_playerScore = 0;
int game_currentBlockPosX = GAME_BLOCK_STARTING_POS_X;
int game_currentBlockPosY = GAME_BLOCK_STARTING_POS_Y;
enum cell_type game_playfield_cellState[GAME_PLAYFIELD_H][GAME_PLAYFIELD_W];
bool game_currentBlockTemplate_cell[4][4];

#ifdef GAME_RULE_ENABLE_RANDOM_KEY
bool game_flag_keyPressed_N = false;
#endif

// Internal variables and constants
const float distanceUpdateThreshold = 1.f / GAME_FPS;
const float distanceGainPerUpdate
    = distanceUpdateThreshold * (float)( GAME_DISTANCE_GAIN_RATE );
float distanceAccumulator = 0.f;


void drawCell( const enum cell_type type )
{
        switch(type) {
        case TYPE_O:
                printf( "%s", GAME_CELL_BLOCK_O );
                break;

        case TYPE_I:
                printf( "%s", GAME_CELL_BLOCK_I );
                break;

        case TYPE_L:
                printf( "%s", GAME_CELL_BLOCK_L );
                break;

        case TYPE_RL:
                printf( "%s", GAME_CELL_BLOCK_RL );
                break;

        case TYPE_S:
                printf( "%s", GAME_CELL_BLOCK_S );
                break;

        case TYPE_RS:
                printf( "%s", GAME_CELL_BLOCK_RS );
                break;

        case TYPE_T:
                printf( "%s", GAME_CELL_BLOCK_T );
                break;

        default:
                printf( "%s", GAME_CELL_BLOCK_NONE );
                break;
        }
}

void drawPlayerScoreBoard() {}

void drawPlayfield()
{
        // Draw the playfield with vertical borders
        for(int row = GAME_PLAYFIELD_VISIBLE_H - 1; row >= 0; row--) {
                printf( "%s", GAME_PLAYFIELD_BORDER );
                for(int column = 0; column < GAME_PLAYFIELD_W; column++) {
                        // Because all blocks are stored in a 4x4 square, this
                        // will check if the current coordinate is within that
                        // square or not
                        if(row > game_currentBlockPosY - 4
                            && row <= game_currentBlockPosY
                            && column >= game_currentBlockPosX
                            && column < game_currentBlockPosX + 4) {
                                // Translate the coordinate on the playfield to
                                // the coordinate in the template square
                                int currentPosX_inTemplate
                                    = ( column - game_currentBlockPosX );
                                int currentPosY_inTemplate
                                    = ( game_currentBlockPosY - row );

                                if(game_currentBlockTemplate_cell
                                        [currentPosY_inTemplate]
                                        [currentPosX_inTemplate])
                                        drawCell( game_currentBlock_type );
                                else if(game_playfield_cellState[row][column]
                                        != TYPE_NONE)
                                        drawCell(
                                            game_playfield_cellState[row]
                                                                    [column] );
                                else
                                        drawCell( TYPE_NONE );
                        } else if(game_playfield_cellState[row][column]
                                  != TYPE_NONE)
                                drawCell(
                                    game_playfield_cellState[row][column] );
                        else
                                drawCell( TYPE_NONE );
                }

                if(row == GAME_PLAYFIELD_VISIBLE_H - 1)
                        printf( "%s\tScore: %d\n", GAME_PLAYFIELD_BORDER,
                            game_playerScore );
                else
                        printf( "%s\n", GAME_PLAYFIELD_BORDER );
        }

        // Draw the bottom horizontal border
        printf( "%s", GAME_PLAYFIELD_BORDER );
        for(int column = 0; column < GAME_PLAYFIELD_W; column++)
                printf( "%s", GAME_PLAYFIELD_BORDER );
        printf( "%s\n", GAME_PLAYFIELD_BORDER );
};

int getNewBlock()
{
        distanceAccumulator = 0;
        game_currentBlockPosX = GAME_BLOCK_STARTING_POS_X;
        game_currentBlockPosY = GAME_BLOCK_STARTING_POS_Y;
        game_currentBlock_type = ( enum cell_type )( rand() % TYPE_COUNT );
        game_currentBlock_rotation = STATE_0;
        if(memcpy( game_currentBlockTemplate_cell,
               game_blockTemplate[game_currentBlock_type][STATE_0],
               sizeof( game_currentBlockTemplate_cell ) )
            == NULL)
                return ERROR_UPDATE_GET_NEW_BLOCK_FAILED;

        return ERROR_NONE;
}

void rotateCurrentBlock()
{
        game_currentBlock_rotation
            = ( game_currentBlock_rotation + 1 ) % STATE_COUNT;
        memcpy( game_currentBlockTemplate_cell,
            game_blockTemplate[game_currentBlock_type]
                              [game_currentBlock_rotation],
            sizeof( game_currentBlockTemplate_cell ) );
}

bool checkBlockValidPos( const int posX, const int posY )
{
        // Iterate all the cells in the template
        for(int row = 0; row < 4; row++) {
                for(int column = 0; column < 4; column++) {
                        // If the current block at specified position is out of
                        // playfield, return false immediately
                        if(game_currentBlockTemplate_cell[row][column]
                            && ( posX + column < 0
                                 || posX + column >= GAME_PLAYFIELD_W
                                 || posY - row < 0 ))
                                return false;

                        // If the current block at specified position overlaps
                        // with any existing cell, return false immediately
                        if(game_currentBlockTemplate_cell[row][column]
                            && game_playfield_cellState[posY - row]
                                                       [posX + column]
                                   != TYPE_NONE)
                                return false;
                }
        }

        return true;
}

bool checkBlockValidState( const enum rotation_state rstate )
{
        // Generate a block with given type and state
        bool blockTemplate[4][4];
        memcpy( blockTemplate,
            game_blockTemplate[game_currentBlock_type][rstate],
            sizeof( blockTemplate ) );

        // Iterate all the cells in the template
        for(int row = 0; row < 4; row++) {
                for(int column = 0; column < 4; column++) {
                        // If the current block at specified position is out of
                        // playfield, return false immediately
                        if(blockTemplate[row][column]
                            && ( game_currentBlockPosX + column < 0
                                 || game_currentBlockPosX + column
                                        >= GAME_PLAYFIELD_W
                                 || game_currentBlockPosY - row < 0 ))
                                return false;

                        // If the current block at specified position overlaps
                        // with any existing cell, return false immediately
                        if(blockTemplate[row][column]
                            && game_playfield_cellState[game_currentBlockPosY
                                                        - row]
                                                       [game_currentBlockPosX
                                                           + column]
                                   != TYPE_NONE)
                                return false;
                }
        }

        return true;
}

bool checkTerminated()
{
        for(int column = 0; column < GAME_PLAYFIELD_W; column++) {
                if(game_playfield_cellState[GAME_PLAYFIELD_VISIBLE_H - 2]
                                           [column]
                    != TYPE_NONE)
                        return true;
        }

        return false;
}

bool checkRowToClear( int* upperRow, int* lowerRow )
{
        int lowerRowToClear = GAME_PLAYFIELD_VISIBLE_H;
        int upperRowToClear = 0;
        bool result = false;
        for(int row = GAME_PLAYFIELD_H - 1; row >= 0; row--) {
                int filledCellCount = 0;
                for(int column = 0; column < GAME_PLAYFIELD_W; column++) {
                        if(game_playfield_cellState[row][column] != TYPE_NONE)
                                filledCellCount++;
                }

                if(filledCellCount == GAME_PLAYFIELD_W) {
                        result = true;

                        if(lowerRowToClear > row)
                                lowerRowToClear = row;
                        if(upperRowToClear < row)
                                upperRowToClear = row;
                }
        }

        *upperRow = upperRowToClear;
        *lowerRow = lowerRowToClear;
        return result;
}

int game_func_init()
{
        // Hide console cursor
        printf( "\33[?25l" );

        // Set seed for rand() to ensure that each time it runs, it will
        // generate a randomized number
        srand( time( NULL ) );

        // Clear the console
        system( "cls" );

        // Init the playfield
        for(int row = 0; row < GAME_PLAYFIELD_H; row++) {
                for(int column = 0; column < GAME_PLAYFIELD_W; column++)
                        game_playfield_cellState[row][column] = TYPE_NONE;
        }

        // Init the current block's template
        for(int row = 0; row < 4; row++) {
                for(int column = 0; column < 4; column++)
                        game_currentBlockTemplate_cell[row][column] = 0;
        }

        return game_init_returnCode = ERROR_NONE;
}

int game_func_draw()
{
        // Move cursor back to the beginning instead of clearing the whole
        // console and draw again
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ),
            (COORD){ 0, 0 } );

        // Draw the playfield and player's current Score
        drawPlayfield();
        drawPlayerScoreBoard();

        return ERROR_NONE;
}

int game_func_getPlayerInput()
{
        // Catch user input
        while(kbhit()) {
                char inputKey = _getch();
                if(inputKey == 'a')
                        game_flag_keyPressed_A = true;
                if(inputKey == 'd')
                        game_flag_keyPressed_D = true;
                if(inputKey == 'r')
                        game_flag_keyPressed_R = true;
                if(inputKey == 'q')
                        game_flag_keyPressed_Q = true;
                if(inputKey == 's')
                        game_flag_keyPressed_S = true;
#ifdef GAME_RULE_ENABLE_RANDOM_KEY
                if(inputKey == 'n')
                        game_flag_keyPressed_N = true;
#endif
        }

        return ERROR_NONE;
}

int game_func_update()
{
        // Resolve force termination request
        if(game_flag_keyPressed_Q) {
                game_flag_forceTerminationRequested = true;
                game_flag_terminated = true;
                return ERROR_NONE;
        }

        // If there is no block, generate a new one
        if(!game_flag_blockExisting) {
                game_flag_blockExisting = true;
                if(getNewBlock() != ERROR_NONE) {
                        game_flag_terminated = true;
                        return game_update_returnCode
                               = ERROR_UPDATE_GET_NEW_BLOCK_FAILED;
                }
        }

        // Resolve moving block left request
        if(game_flag_keyPressed_A
            && checkBlockValidPos( game_currentBlockPosX - 1,
                game_currentBlockPosY ))
                game_currentBlockPosX--;

        // Resolve moving block right request
        if(game_flag_keyPressed_D
            && checkBlockValidPos( game_currentBlockPosX + 1,
                game_currentBlockPosY ))
                game_currentBlockPosX++;


        // Resolve block rotating request
        if(game_flag_keyPressed_R) {
                enum rotation_state nextState
                    = ( game_currentBlock_rotation + 1 ) % STATE_COUNT;
                if(checkBlockValidState( nextState ))
                        rotateCurrentBlock();
        }

        // Resolve instant drop request
        if(game_flag_keyPressed_S && game_flag_blockExisting) {
                while(checkBlockValidPos( game_currentBlockPosX,
                    game_currentBlockPosY - 1 )) {
                        distanceAccumulator += distanceGainPerUpdate;
                        if(distanceAccumulator
                            >= distanceUpdateThreshold * (float)( GAME_FPS )) {
                                game_currentBlockPosY--;
                                distanceAccumulator = 0.f;
                        }
                }

                for(int row = 0; row < 4; row++) {
                        for(int column = 0; column < 4; column++) {
                                if(game_currentBlockTemplate_cell[row][column])
                                        game_playfield_cellState
                                            [game_currentBlockPosY - row]
                                            [game_currentBlockPosX + column]
                                            = game_currentBlock_type;
                        }
                }

                game_flag_blockExisting = false;
        }

// Resolve new block manual request
#ifdef GAME_RULE_ENABLE_RANDOM_KEY
        if(game_flag_keyPressed_N) {
                if(getNewBlock() != ERROR_NONE) {
                        game_flag_terminated = true;
                        return game_update_returnCode
                               = ERROR_UPDATE_GET_NEW_BLOCK_FAILED;
                }
        }
#endif

        // Update state of current block
        if(game_flag_blockExisting) {
                if(checkBlockValidPos( game_currentBlockPosX,
                       game_currentBlockPosY - 1 )) {
                        distanceAccumulator += distanceGainPerUpdate;
                        if(distanceAccumulator
                            >= distanceUpdateThreshold * (float)( GAME_FPS )) {
                                game_currentBlockPosY--;
                                distanceAccumulator = 0.f;
                        }
                } else {
                        game_flag_enableLockDelayFrameCounter = true;
                        if(game_lockDelayFrameCounter
                            >= GAME_LOCK_DELAY_FRAME_LIMIT) {
                                for(int row = 0; row < 4; row++) {
                                        for(int column = 0; column < 4;
                                            column++) {
                                                if(game_currentBlockTemplate_cell
                                                        [row][column])
                                                        game_playfield_cellState
                                                            [game_currentBlockPosY
                                                                - row]
                                                            [game_currentBlockPosX
                                                                + column]
                                                            = game_currentBlock_type;
                                        }
                                }

                                game_flag_blockExisting = false;
                                game_flag_enableLockDelayFrameCounter = false;
                                game_lockDelayFrameCounter = 0;
                        } else if(game_flag_enableLockDelayFrameCounter)
                                game_lockDelayFrameCounter++;
                }
        }

        // If there is any row to clear, clear and update the playfield
        int upperRow = 0;
        int lowerRow = 0;
        if(checkRowToClear( &upperRow, &lowerRow )) {
                for(int rowToUpdate = upperRow; rowToUpdate >= lowerRow;
                    rowToUpdate--) {
                        for(int currenRow = rowToUpdate + 1;
                            currenRow < GAME_PLAYFIELD_H; currenRow++)
                                memcpy( game_playfield_cellState[currenRow - 1],
                                    game_playfield_cellState[currenRow],
                                    sizeof( game_playfield_cellState[currenRow
                                                                     - 1] ) );
                }

                game_playerScore += ( upperRow - lowerRow + 1 );
        }

        // Check if the game should be terminated without player's request
        if(checkTerminated()) {
                game_flag_terminated = true;
                return ERROR_NONE;
        }

        // Reset all flags
        game_flag_keyPressed_A = false;
        game_flag_keyPressed_D = false;
        game_flag_keyPressed_R = false;
        game_flag_keyPressed_Q = false;
        game_flag_keyPressed_S = false;

#ifdef GAME_RULE_ENABLE_RANDOM_KEY
        game_flag_keyPressed_N = false;
#endif

        return ERROR_NONE;
}

int game_func_terminate()
{
        // Check error code and return it if there is
        if(game_init_returnCode != ERROR_NONE)
                return game_exitCode = game_init_returnCode;
        if(game_update_returnCode != ERROR_NONE)
                return game_exitCode = game_update_returnCode;

        // If there is no error, clear the console and print the player's final
        // score
        system( "cls" );
        if(game_flag_forceTerminationRequested)
                printf( "Game terminated\n" );
        else
                printf( "Game over\n" );
        printf( "Your final score: %d\n", game_playerScore );
        printf( "Press any key to quit" );
        getch();

        // Re-enable the console cursor
        printf( "\33[?25h" );
        return game_exitCode = ERROR_NONE;
}