/*
** EPITECH PROJECT, 2021
** init_data_set.c
** File description:
** init_data_set function
*/

#include "mylibc.h"
#include "sokoban.h"

set_t *init_data_set(char *map)
{
    set_t *set = malloc(sizeof(set_t));

    set->origin = map;
    set->map = word_array_delim(map, '\n');
    get_player_position(set);
    get_pos_char(set, 'O');
    set->total_X = get_total_target(set, 'X');
    if (!set->P_pos || set->total_O == 0 || set->total_X == 0 || \
        set->total_O < set->total_X) {
            free_set(set);
            return NULL;
        }
    set->window_ok = true;
    set->victory = false;
    set->defeat = false;
    return set;
}
