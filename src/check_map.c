/*
** EPITECH PROJECT, 2021
** check_map.c
** File description:
** check_map function
*/

#include "mylibc.h"

bool check_map(char *map)
{
    for (int i = 0; map[i]; ++i) {
        if (map[i] != '#' && map[i] != 'X' && map[i] != 'O' && \
            map[i] != 'P' && map[i] != '\n' && map[i] != ' ')
            return false;
    }
    return true;
}

