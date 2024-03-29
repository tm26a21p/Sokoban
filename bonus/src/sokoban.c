/*
** EPITECH PROJECT, 2021
** sokoban.c
** File description:
** sokoban fonction
*/

#include "mylibc.h"
#include "sokoban.h"
#include <ncurses.h>
#include <unistd.h>

int my_sokoban(set_t *set)
{
    initscr();
    cbreak();
    start_color();
    keypad(stdscr, TRUE);
    while (!set->victory && !set->defeat) {
        erase();
        display_map(set->map);
        check_window_size(set);
        check_end(set);
        listen_user_input(set);
    }
    usleep(250000);
    listen_replay(set);
    return game_end(set);
}

