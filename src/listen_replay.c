/*
** EPITECH PROJECT, 2021
** listen_replay.c
** File description:
** listen_replay function
*/

#include "mylibc.h"
#include "sokoban.h"
#include <ncurses.h>

void listen_replay(set_t *set)
{
    char *play_again = "Space bar to replay. Any other key to quit.";
    int input = 0;
    int x = 0;
    int y = 0;

    free_word_array(set->map);
    free(set->O_pos);
    free(set->P_pos);
    getmaxyx(stdscr, x, y);
    clear();
    mvprintw((x - 1) / 2, (y - my_strlen(play_again)) / 2, "%s", play_again);
    input = getch();
    if (input == ' ') {
        set = init_data_set(set->origin);
        my_sokoban(set);
    }
}

