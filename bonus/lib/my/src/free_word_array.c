/*
** EPITECH PROJECT, 2021
** free_word_array.c
** File description:
** free_word_array function
*/

#include "mylibc.h"

void free_word_array(char **word_array)
{
    for (int i = 0; word_array[i]; i++)
        free(word_array[i]);
    free(word_array);
}
