/*
** EPITECH PROJECT, 2021
** free_set.c
** File description:
** free_set function
*/

#include "mylibc.h"

void free_set(set_t *set)
{
    free_word_array(set->map);
    free(set->origin);
    free(set);
}

