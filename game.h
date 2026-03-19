#pragma once

#include <stdbool.h>

// #define GAME_RULE_ENABLE_RANDOM_KEY

#define GAME_DISTANCE_GAIN_RATE 3.5
#define GAME_FPS (time_t)(60)
#define GAME_UPDATE_INTERVAL (time_t)(1000 / GAME_FPS)
#define GAME_FUZZY_TIME_INTERVAL 15
#define GAME_LOCK_DELAY_FRAME_LIMIT 18
#define GAME_CELL_EMPTY_CHAR ' '
#define GAME_CELL_OCCUPIED_CHAR '#'
#define GAME_CELL_STATE_OCCUPIED true
#define GAME_CELL_STATE_EMPTY false
#define GAME_PLAYFIELD_W 10
#define GAME_PLAYFIELD_H 24
#define GAME_PLAYFIELD_VISIBLE_H (GAME_PLAYFIELD_H - 4)
#define GAME_PLAYFIELD_BORDER_HORIZONTAL_CHAR '-'
#define GAME_PLAYFIELD_BORDER_VERTICAL_CHAR '|'
#define GAME_PLAYFIELD_BORDER_CORNER_CHAR '+'
#define GAME_BLOCK_STARTING_POS_X (GAME_PLAYFIELD_W / 2 - 2)
#define GAME_BLOCK_STARTING_POS_Y (GAME_PLAYFIELD_H - 1)

enum error_code {
        ERROR_NONE,
        ERROR_UPDATE_GET_NEW_BLOCK_FAILED
};

enum block_type {
        TYPE_O, // Default type
        TYPE_I,
        TYPE_L,
        TYPE_RL,
        TYPE_S,
        TYPE_RS,
        TYPE_T,
        TYPE_COUNT
};

enum rotation_state {
        STATE_0, // Default state
        STATE_1,
        STATE_2,
        STATE_3,
        STATE_COUNT
};

extern const bool game_blockTemplate[TYPE_COUNT][STATE_COUNT][4][4];

extern bool game_flag_keyPressed_A;
extern bool game_flag_keyPressed_D;
extern bool game_flag_keyPressed_R;
extern bool game_flag_keyPressed_S;
extern bool game_flag_keyPressed_Q;
extern bool game_flag_forceTerminationRequested;
extern bool game_flag_terminated;
extern bool game_flag_blockExisting;
extern bool game_flag_enableLockDelayFrameCounter;
extern int game_lockDelayFrameCounter;
extern int game_init_returnCode;
extern int game_update_returnCode;
extern int game_playerScore;
extern int game_exitCode;
extern enum block_type game_currentBlock_type;
extern enum rotation_state game_currentBlock_rotation;
extern int game_currentBlockPosX;
extern int game_currentBlockPosY;
extern bool game_cellState[GAME_PLAYFIELD_H][GAME_PLAYFIELD_W];
extern bool game_currentBlockTemplate[4][4];

#ifdef GAME_RULE_ENABLE_RANDOM_KEY
extern bool game_flag_keyPressed_N;
#endif

int game_func_init();
int game_func_draw();
int game_func_getPlayerInput();
int game_func_update();
int game_func_terminate();