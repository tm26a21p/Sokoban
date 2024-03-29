/*
** EPITECH PROJECT, 2021
** move_player.c
** File description:
** move_player function
*/

#include "mylibc.h"
#include <ncurses.h>

void check_o_pos(pos_t *O_pos, pos_t *P, pos_t *is_o)
{
    for (int i = 0; O_pos[i].x != - 4; i++) {
        if (O_pos[i].x == P->x && O_pos[i].y == P->y) {
            is_o->x = O_pos[i].x;
            is_o->y = O_pos[i].y;
            return;
        }
    }
    is_o->x = -1;
}

void move_player(set_t *set, int x, int y)
{
    pos_t is_o;
    char next = set->map[set->P_pos->x + x][set->P_pos->y + y];

    if (next != '#') {
        if (next == 'X' && (set->map[set->P_pos->x + (x * 2)]\
                                    [set->P_pos->y + (y * 2)] == '#' || \
            set->map[set->P_pos->x + (x * 2)]\
                    [set->P_pos->y + (y * 2)] == 'X')) {
                return;
            }
        if (next == 'X' && set->map[set->P_pos->x + (x * 2)]\
                                    [set->P_pos->y + (y * 2)] != '#')
                set->map[set->P_pos->x + (x * 2)]\
                        [set->P_pos->y + (y * 2)] = 'X';
        check_o_pos(set->O_pos, set->P_pos, &is_o);
        if (is_o.x != -1)
            set->map[set->P_pos->x][set->P_pos->y] = 'O';
        else
            set->map[set->P_pos->x][set->P_pos->y] = ' ';
        set->map[set->P_pos->x += x][set->P_pos->y += y] = 'P';
    }
}
