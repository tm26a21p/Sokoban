/*
** EPITECH PROJECT, 2021
** free_list.c
** File description:
** free_list function
*/

#include "mylibc.h"

void free_list(pnode_t node)
{
    pnode_t tmp = NULL;

    while (node) {
        tmp = node;
        node = node->next;
        free(tmp->data);
        free(tmp);
    }
}

