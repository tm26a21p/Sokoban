/*
** EPITECH PROJECT, 2021
** tests.c
** File description:
** tests.c function
*/

#include "sokoban.h"
#include "mylibc.h"
#include <ncurses.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(get_player_position, check_player_pos)
{
    set_t *set = malloc(sizeof(set_t));
    set->origin = load_file_in_mem("map/map.txt");
    set->map = word_array_delim(set->origin, '\n');

    get_player_position(set);
    cr_assert_eq(set->P_pos->x, 3);
    cr_assert_eq(set->P_pos->y, 5);
    free_set(set);
}

Test(get_player_position, go_through_all_tab_stupid_coverage)
{
    set_t *set = malloc(sizeof(set_t));
    set->origin = load_file_in_mem("map/incorrect_map.txt");
    set->map = word_array_delim(set->origin, '\n');

    get_player_position(set);
    cr_assert_neq(set->P_pos->x, 3);
    cr_assert_neq(set->P_pos->y, 5);
    free_set(set);
}

Test(get_player_position, more_than_1_player)
{
    set_t *set = malloc(sizeof(set_t));
    set->origin = load_file_in_mem("map/invalid_map_2_players.txt");
    set->map = word_array_delim(set->origin, '\n');

    get_player_position(set);
    cr_assert_null(set->P_pos);
    free_set(set);
}

Test(get_total_target, correct_map)
{
    set_t *set = malloc(sizeof(set_t));
    set->origin = load_file_in_mem("map/map.txt");
    set->map = word_array_delim(set->origin, '\n');

    set->total_O = get_total_target(set, 'O');
    cr_assert_eq(set->total_O, 3);
    free_set(set);
}

Test(get_total_target, incorrect_map)
{
    set_t *set = malloc(sizeof(set_t));
    set->origin = load_file_in_mem("map/incorrect_map.txt");
    set->map = word_array_delim(set->origin, '\n');

    set->total_O = get_total_target(set, 'O');
    cr_assert_eq(set->total_O, 0);
    free_set(set);
}

Test(get_pos_char, valid_get_pos_char_O)
{
    set_t *set = malloc(sizeof(set_t));
    set->origin = load_file_in_mem("map/map.txt");
    set->map = word_array_delim(set->origin, '\n');

    get_pos_char(set, 'O');
    cr_assert_eq(set->O_pos[0].x, 1);
    cr_assert_eq(set->O_pos[0].y, 2);
    cr_assert_eq(set->O_pos[1].x, 1);
    cr_assert_eq(set->O_pos[1].y, 15);
    cr_assert_eq(set->O_pos[2].x, 2);
    cr_assert_eq(set->O_pos[2].y, 2);
    free_set(set);
}

Test(get_pos_char, invalid_get_pos_char_O)
{
    set_t *set = malloc(sizeof(set_t));
    set->origin = load_file_in_mem("map/incorrect_map.txt");
    set->map = word_array_delim(set->origin, '\n');

    get_pos_char(set, 'O');
    cr_assert_null(set->O_pos);
    free_set(set);
}

Test(init_data_set, invalid_map)
{
    set_t *set = init_data_set(load_file_in_mem("map/incorrect_map.txt"));

    cr_assert_null(set);
}

Test(init_data_set, valid_map)
{
    set_t *set = init_data_set(load_file_in_mem("map/map.txt"));

    cr_assert_neq(set, NULL);
}

Test(check_end, not_the_end_yet)
{
    set_t *set = init_data_set(load_file_in_mem("map/map.txt"));

    check_end(set);
    cr_assert_eq(set->defeat, false);
    cr_assert_eq(set->victory, false);
}

Test(check_end, end_on_loose)
{
    set_t *set = init_data_set(load_file_in_mem("map/lost_map.txt"));

    check_end(set);
    cr_assert_eq(set->defeat, true);
    cr_assert_eq(set->victory, false);
}

Test(check_end, end_on_win)
{
    set_t *set = init_data_set(load_file_in_mem("map/almost_won_map.txt"));

    set->map[1][2] = ' ';
    set->map[1][1] = 'X';
    check_end(set);
    cr_assert_eq(set->defeat, false);
    cr_assert_eq(set->victory, true);
}

Test(len_map, check_map_len_ok)
{
    set_t *set = init_data_set(load_file_in_mem("map/map.txt"));
    int t = len_map(set->map);

    cr_assert_eq(t, 7);
}

Test(check_map, check_map_char_not_ok)
{
    char *map = load_file_in_mem("map/invalid_char_map.txt");
    bool bob = check_map(map);

    cr_assert_eq(bob, 0);
}

Test(check_map, check_map_char_ok)
{
    char *map = load_file_in_mem("map/map.txt");
    bool bob = check_map(map);

    cr_assert_eq(bob, 1);
}