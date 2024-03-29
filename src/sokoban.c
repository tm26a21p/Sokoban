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
    keypad(stdscr, TRUE);
    while (!set->victory && !set->defeat) {
        erase();
        check_window_size(set);
        display_map(set->map);
        listen_user_input(set);
        display_map(set->map);
        refresh();
        check_end(set);
    }
    return game_end(set);
}

