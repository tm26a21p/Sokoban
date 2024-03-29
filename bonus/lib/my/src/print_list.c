/*
** EPITECH PROJECT, 2021
** print_list.c
** File description:
** print_list function
*/

#include "mylibc.h"

void print_list(pnode_t head)
{
    for (pnode_t tmp = head; tmp; tmp = tmp->next)
        my_printf("%s\n", tmp->data);
}
