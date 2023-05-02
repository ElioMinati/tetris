/*
** EPITECH PROJECT, 2022
** detect_touching.c
** File description:
** functions used to detect the touching
*/

#include "tetris.h"

static void remove_line(char **map, int i)
{
    for (int j = i; j > 0; --j) {
        for (int k = 0; map[j][k] != '\0'; ++k) {
            map[j][k] =  map[j - 1][k];
        }
    }
}

static int add_count(char **map, int i, int j)
{
    if (map[i][j] != ' ')
        return 1;
    return 0;
}

void detect_full_line(char **map, tetris_t *game)
{
    int j;
    int count = 0;

    for (int i = 0; map[i] != NULL; ++i) {
        for (j = 0; map[i][j] != '\0'; ++j) {
            count += add_count(map, i, j);
        }
        if (count == j) {
            game->score += 10;
            remove_line(map, i);
        }
        count = 0;
    }
}
