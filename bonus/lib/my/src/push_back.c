/*
** EPITECH PROJECT, 2021
** push_back.c
** File description:
** push_back function
*/

#include "mylibc.h"

int push_back(pnode_t *head, char *str)
{
    pnode_t current = *head;
    pnode_t node = malloc(sizeof(node_list_t));

    if (!node)
        return EXIT_ERR_MALLOC;
    node->data = my_strdup(str);
    node->next = NULL;
    if (!*head)
        *head = node;
    else {
        while (current->next)
            current = current->next;
        current->next = node;
    }
    return EXIT_SUCCESS;
}

