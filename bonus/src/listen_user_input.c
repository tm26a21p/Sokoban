/*
** EPITECH PROJECT, 2021
** listen_user_input.c
** File description:
** listen_user_input function
*/

#include "mylibc.h"
#include "sokoban.h"
#include <ncurses.h>

void listen_user_input(set_t *set)
{
    timer();
    int input = getch();

    if (!set->window_ok)
        return;
    if (input == KEY_LEFT)
        move_player(set, 0, -1);
    if (input == KEY_RIGHT)
        move_player(set, 0, 1);
    if (input == KEY_DOWN)
        move_player(set, 1, 0);
    if (input == KEY_UP)
        move_player(set, -1, 0);
}
