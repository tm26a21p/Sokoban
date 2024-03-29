/*
** EPITECH PROJECT, 2021
** get_total_target.c
** File description:
** get_total_target function
*/

#include "mylibc.h"

int get_total_target(set_t *set, char target)
{
    int count = 0;

    for (int i = 0; set->map[i]; ++i) {
        for (int j = 0; set->map[i][j]; ++j) {
            if (set->map[i][j] == target)
                ++count;
        }
    }
    return count;
}

