/*
** EPITECH PROJECT, 2021
** check_window_size.c
** File description:
** check_window_size function
*/

#include "mylibc.h"
#include "sokoban.h"
#include <ncurses.h>

int max_len_y(char **map)
{
    int max = 0;
    int tmp = 0;

    for (int i = 0; map[i]; i++) {
        tmp = my_strlen(map[i]);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

void check_window_size(set_t *set)
{
    int x = 0;
    int y = 0;
    int map_x = len_map(set->map);
    int map_y = max_len_y(set->map);
    WINDOW *w;
    char *msg = "Please resize window!";

    getmaxyx(stdscr, x, y);
    if (x < map_x || y < map_y) {
        set->window_ok = false;
        erase();
        refresh();
        w = newwin(x / 2, y / 2, x / 2 - (x / 4), y / 2 - (y / 4));
        box(w, 0, 0);
        mvwprintw(w, x / 4, (y - my_strlen(msg) * 2) / 4, "%s", msg);
        wrefresh(w);
        refresh();
    }
    else
        set->window_ok = true;
}

