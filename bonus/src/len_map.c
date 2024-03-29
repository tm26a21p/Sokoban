/*
** EPITECH PROJECT, 2021
** len_map.c
** File description:
** len_map function
*/

#include "mylibc.h"

int len_map(char **map)
{
    int i = 0;

    for (; map[i]; i++);
    return i + 1;
}

