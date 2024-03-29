/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** structs definition
*/


#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdarg.h>
#include <stdbool.h>

typedef struct cpf
{
    char c;
    void (*pf) (va_list ap);
} cpf;

typedef struct node_list_s
{
    char *data;
    struct node_list_s *next;
} node_list_t, *pnode_t;

typedef struct position_s
{
    int x;
    int y;
} pos_t;

typedef struct sokoban_s
{
    char *origin;
    char **map;
    pos_t *P_pos;
    pos_t *O_pos;
    int total_O;
    int total_X;
    bool window_ok;
    bool victory;
    bool defeat;
} set_t;

#endif
