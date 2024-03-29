/*
** EPITECH PROJECT, 2021
** word_array_delim.c
** File description:
** word_array_delim function
*/

#include "mylibc.h"
#include <stdlib.h>

int count_lines(char *str, char d)
{
    int i = 0;
    int c = 0;

    for (; str[i]; i++) {
        if (str[i] == d)
            c = c + 1;
    }
    return c + 1;
}

int word_len_delim(char *str, char d)
{
    int i = 0;

    for (; str[i] != d; ++i) {
        if (str[i] == '\0')
            break;
    }
    return i;
}

char **word_array_delim(char *str, char d)
{
    int total_lines = count_lines(str, d);
    char **tab = malloc(sizeof(char *) * (total_lines + 1));

    for (int a = 0, i = 0, wl = 0; i < total_lines; ++i, ++a) {
        wl = word_len_delim(&str[a], d);
        tab[i] = malloc(sizeof(char) * (wl + 1));
        tab[i] = my_strncpy(tab[i], &str[a], wl);
        a += wl;
    }
    tab[total_lines] = NULL;
    return tab;
}