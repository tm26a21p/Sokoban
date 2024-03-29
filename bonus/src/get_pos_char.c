/*
** EPITECH PROJECT, 2021
** get_pos_char.c
** File description:
** get_pos_char function
*/

#include "mylibc.h"
#include "sokoban.h"

void get_pos_char(set_t *set, char c)
{
    int x = 0;

    set->total_O = get_total_target(set, c);
    if (set->total_O == 0) {
        set->O_pos = NULL;
        return;
    }
    set->O_pos = malloc(sizeof(pos_t) * (set->total_O + 1));
    for (int i = 0; set->map[i]; i++) {
        for (int j = 0; set->map[i][j]; j++) {
            if (set->map[i][j] == c) {
                set->O_pos[x].x = i;
                set->O_pos[x].y = j;
                x++;
            }
        }
    }
    set->O_pos[x].x = -4;
    set->O_pos[x].y = -4;
}

