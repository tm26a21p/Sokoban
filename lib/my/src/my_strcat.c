/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** concatenates 2 strings
*/

#include "mylibc.h"
#include <stdlib.h>
#include <stdio.h>

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;

    for (; src[i]; ++i) {
        dest[len + i] = src[i];
    }
    dest[len + i] = '\0';
    return dest;
}
