/*
** EPITECH PROJECT, 2021
** my_worldlen.c
** File description:
** return the length of the word
*/

#include <mylibc.h>

int my_wordlen(char const *str)
{
    int i = 0;

    while (my_alphanum(str[i]) != 0)
        ++i;
    return i;
}
