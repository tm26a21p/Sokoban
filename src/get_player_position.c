/*
** EPITECH PROJECT, 2021
** get_player_position.c
** File description:
** get_player_position function
*/

#include "mylibc.h"

void get_player_position(set_t *set)
{
    int check = 0;
    set->P_pos = malloc(sizeof(pos_t));

    for (int i = 0; set->map[i]; i++) {
        for (int j = 0; set->map[i][j]; j++) {
            if (check > 1) {
                set->P_pos = NULL;
                return;
            }
            if (set->map[i][j] == 'P') {
                set->P_pos->x = i;
                set->P_pos->y = j;
                check++;
            }
        }
    }
}

