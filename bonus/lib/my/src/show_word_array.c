/*
** EPITECH PROJECT, 2021
** show_word_array.c
** File description:
** display the content of an array of word
*/

#include <string.h>
#include "mylibc.h"

void show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; ++i)
        my_printf("%s\n", tab[i]);
}
