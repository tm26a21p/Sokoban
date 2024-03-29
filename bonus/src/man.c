/*
** EPITECH PROJECT, 2021
** man.c
** File description:
** man fonction
*/

#include "mylibc.h"

void man(void)
{
    my_printf("USAGE\n");
    my_printf("\t./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("\tmap file representing the warehouse map, coutaining ");
    my_printf("`#' for walls, `P' for the player, `X' for boxes and `0' ");
    my_printf("for storage locations.\n");
}

