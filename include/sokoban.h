/*
** EPITECH PROJECT, 2021
** sokoban.h
** File description:
** sokoban header file
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include "mylibc.h"

void man(void);
int my_sokoban(set_t *set);
char **get_map(char *map);
int get_total_target(set_t *set, char target);
set_t *init_data_set(char *map);
void display_map(char **map);
void listen_user_input(set_t *set);
void get_player_position(set_t *set);
void get_pos_char(set_t *set, char c);
void move_player(set_t *set, int x, int y);
void check_window_size(set_t *set);
void check_end(set_t *set);
int game_end(set_t *set);
void listen_replay(set_t *set);
void free_set(set_t *set);
int len_map(char **map);
bool check_map(char *map);

#endif // end of sokoban.h definition condition
