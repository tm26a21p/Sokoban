/*
** EPITECH PROJECT, 2021
** len_list.c
** File description:
** len_list function
*/

#include "mylibc.h"

int len_list(pnode_t head)
{
    int count = 0;

    for (pnode_t tmp = head; tmp; tmp = tmp->next, count++);
    return count;
}

