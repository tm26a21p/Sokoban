/*
** EPITECH PROJECT, 2021
** push_front.c
** File description:
** push_front function
*/

#include "mylibc.h"

int push_front(pnode_t *head, char *str)
{
    pnode_t node = malloc(sizeof(node_list_t));

    if (!node)
        return EXIT_ERR_MALLOC;
    node->data = my_strdup(str);
    if (!*head) {
        node->next = NULL;
        *head = node;
    }
    else {
        node->next = *head;
        *head = node;
    }
    return EXIT_SUCCESS;
}

