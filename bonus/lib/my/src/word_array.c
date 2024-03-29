/*
** EPITECH PROJECT, 2021
** word_array.c
** File description:
** function that splits astring into words. Separators will
** all be non-alphanumeric characters.The function returns an
** array in which each cell contains the address of a string
** (representing a word).The last cell must be null to terminate the array
*/

#include <stdio.h>
#include <stdlib.h>
#include "mylibc.h"

char **word_array(char const *str)
{
    int total_word = my_str_count_word(str);
    char **dest = malloc(sizeof(char *) * (total_word + 1));

    for (int a = 0, i = 0, wl = 0; i < total_word; ++i) {
        while (my_alphanum(str[a]) == 0)
            a++;
        wl = my_wordlen(&str[a]);
        dest[i] = malloc(sizeof(char) * (wl + 1));
        dest[i] = my_strncpy(dest[i], &str[a], wl);
        a += wl;
    }
    dest[total_word] = NULL;
    return (dest);
}
