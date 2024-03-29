/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** basic main
*/

#include "mylibc.h"
#include "sokoban.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    char *map = NULL;
    set_t *set = NULL;
    int return_value = 0;

    if (ac != 2)
        return (EXIT_ERROR_USAGE);
    if (my_strcmp(av[1], "-h") == 0 || my_strcmp(av[1], "--help") == 0) {
        man();
        return (EXIT_USAGE);
    }
    map = load_file_in_mem(av[1]);
    if (!map)
        return (EXIT_ERROR_MAP);
    set = init_data_set(map);
    if (!set)
        return (EXIT_ERROR_MAP);
    return_value = my_sokoban(set);
    free(set);
    return return_value;
}
