/*
** EPITECH PROJECT, 2021
** display_map.c
** File description:
** display_map function
*/

#include "mylibc.h"
#include "sokoban.h"
#include <ncurses.h>

void display_map(char **map)
{
    int x = 0;
    int y = 0;

    getmaxyx(stdscr, x, y);
    for (int i = 0; map[i]; i++)
        mvprintw((x - len_map(map)) / 2 + i, \
            (y - my_strlen(map[i])) / 2, "%s\n", map[i]);
}

