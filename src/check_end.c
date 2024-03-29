/*
** EPITECH PROJECT, 2021
** check_end.c
** File description:
** check_end function
*/

#include "mylibc.h"
#include <ncurses.h>
#include <stdio.h>

void check_loose(set_t *set)
{
    int check = 0;

    for (int i = 0; set->map[i]; i++) {
        for (int j = 0; set->map[i][j]; j++) {
            if ((set->map[i][j] == 'X') && \
                (((set->map[i][j - 1] == '#' || set->map[i][j - 1] == 'X') && \
                (set->map[i - 1][j] == '#' || set->map[i - 1][j] == 'X')) || \
                ((set->map[i - 1][j] == '#' || set->map[i - 1][j] == 'X') && \
                (set->map[i][j + 1] == '#' || set->map[i][j + 1] == 'X')) || \
                ((set->map[i][j + 1] == '#' || set->map[i][j + 1] == 'X') && \
                (set->map[i + 1][j] == '#' || set->map[i + 1][j] == 'X')) || \
                ((set->map[i + 1][j] == '#' || set->map[i + 1][j] == 'X') && \
                (set->map[i][j - 1] == '#' || set->map[i][j - 1] == 'X'))))
                    check++;
        }
    }
    if (check == set->total_X)
        set->defeat = true;
}

void check_win(set_t *set)
{
    int count_x = 0;

    for (int i = 0; i < set->total_O; ++i) {
        if (set->map[set->O_pos[i].x][set->O_pos[i].y] == 'X')
            count_x++;
    }
    if (count_x == set->total_O)
        set->victory = true;
}

void check_end(set_t *set)
{
    check_win(set);
    if (set->victory)
        return;
    check_loose(set);
}

