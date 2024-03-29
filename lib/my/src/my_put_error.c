/*
** EPITECH PROJECT, 2021
** my_put_error.c
** File description:
** my_put_error function
*/

#include "mylibc.h"
#include <unistd.h>

int my_put_error(char *str)
{
    return write(2, str, my_strlen(str));
}
