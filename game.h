#pragma once

#include <stdbool.h>

// #define GAME_RULE_ENABLE_RANDOM_KEY

#define GAME_DISTANCE_GAIN_RATE 3.0f
#define GAME_FPS (time_t)( 60 )
#define GAME_FUZZY_TIME_INTERVAL 18
#define GAME_LOCK_DELAY_FRAME_LIMIT 5
#define GAME_PLAYFIELD_W 10
#define GAME_PLAYFIELD_H 24
#define GAME_UPDATE_INTERVAL (time_t)( 1000 / GAME_FPS )
#define GAME_PLAYFIELD_VISIBLE_H ( GAME_PLAYFIELD_H - 4 )
#define GAME_BLOCK_STARTING_POS_X ( GAME_PLAYFIELD_W / 2 - 2 )
#define GAME_BLOCK_STARTING_POS_Y ( GAME_PLAYFIELD_H - 1 )
#define GAME_CELL_BLOCK_O "\033[103m \033[0m"
#define GAME_CELL_BLOCK_I "\033[46m \033[0m"
#define GAME_CELL_BLOCK_L "\033[44m \033[0m"
#define GAME_CELL_BLOCK_RL "\033[43m \033[0m"
#define GAME_CELL_BLOCK_S "\033[41m \033[0m"
#define GAME_CELL_BLOCK_RS "\033[42m \033[0m"
#define GAME_CELL_BLOCK_T "\033[45m \033[0m"
#define GAME_CELL_BLOCK_NONE "\033[0m \033[0m"
#define GAME_PLAYFIELD_BORDER "\033[100m \033[0m"

enum error_code { ERROR_NONE, ERROR_UPDATE_GET_NEW_BLOCK_FAILED };

enum cell_type {
        TYPE_O, // Default type
        TYPE_I,
        TYPE_L,
        TYPE_RL,
        TYPE_S,
        TYPE_RS,
        TYPE_T,
        TYPE_COUNT,
        TYPE_NONE
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
extern enum cell_type game_currentBlock_type;
extern enum rotation_state game_currentBlock_rotation;
extern int game_currentBlockPosX;
extern int game_currentBlockPosY;
extern enum cell_type game_playfield_cellState[GAME_PLAYFIELD_H]
                                              [GAME_PLAYFIELD_W];
extern bool game_currentBlockTemplate_cell[4][4];

#ifdef GAME_RULE_ENABLE_RANDOM_KEY
extern bool game_flag_keyPressed_N;
#endif

int game_func_init();
int game_func_draw();
int game_func_getPlayerInput();
int game_func_update();
int game_func_terminate();