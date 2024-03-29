/*
** EPITECH PROJECT, 2021
** load_file_in_mem.c
** File description:
** load a map content in memory
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "mylibc.h"

char *load_file_in_mem(char const *filepath)
{
    int fd = open_file(filepath);
    struct stat sb;
    char *buff = NULL;

    if (fd == 84 || stat(filepath, &sb) == -1)
        return NULL;
    buff = malloc(sizeof(char) * (sb.st_size + 1));
    if (read(fd, buff, sb.st_size) == 0)
        return NULL;
    buff[sb.st_size] = '\0';
    close(fd);
    return buff;
}