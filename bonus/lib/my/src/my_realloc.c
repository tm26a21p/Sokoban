/*
** EPITECH PROJECT, 2021
** my_realloc.c
** File description:
** my_realloc fonction
*/

#include "mylibc.h"
#include <stdlib.h>

char *my_realloc(char *str, int n)
{
    char *cpy = NULL;

    if (str && n == 0) {
        free(str);
        return NULL;
    }
    if (!str) {
        cpy = malloc(sizeof(char) * (n + 1));
        return cpy;
    }
    else
        cpy = malloc(sizeof(char) * (n + 1));
    cpy = my_strncpy(cpy, str, n);
    free(str);
    return cpy;
}

