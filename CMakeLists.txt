cmake_minimum_required(VERSION 4.2.3)
project(Tetris_C
        LANGUAGES C
)

set(CMAKE_C_STANDARD 17)

add_library(gameHeader)
target_sources(gameHeader
        PRIVATE game.c
        
        PUBLIC
                FILE_SET HEADERS
                FILES game.h
)
target_compile_options(gameHeader
        PRIVATE -glldb
)

add_executable(game)
target_sources(game
        PRIVATE main.c
)
target_link_libraries(game
        gameHeader
)
target_compile_options(game
        PRIVATE -glldb
)