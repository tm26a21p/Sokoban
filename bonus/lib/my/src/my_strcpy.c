/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** copies a string into another
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
