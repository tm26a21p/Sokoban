/*
** EPITECH PROJECT, 2021
** game_end.c
** File description:
** game_end function
*/

#include "mylibc.h"
#include <ncurses.h>
#include <unistd.h>

int game_end(set_t *set)
{
    endwin();
    if (set->defeat) {
        return 1;
    }
    return 0;
}

