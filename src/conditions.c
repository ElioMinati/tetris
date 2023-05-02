/*
** EPITECH PROJECT, 2022
** conditions.c
** File description:
** functions that do conditions
*/

#include "tetris.h"

int is_hit(tetris_t *game, char **map, int i, vector2i size)
{
    for (int j = 0; game->current_shape.shape[i][j] != '\0'; ++j) {
        if (map[game->current_shape.offset.y + i][game->current_shape.offset.x
        + j + size.col / 2] != ' ' && game->current_shape.shape[i][j] == '*') {
            game->current_shape.offset.y -= 1;
            return 1;
        }
    }
    return 0;
}

void add_into_map(shape_t current_shape, int i, char **map, vector2i size)
{
    for (int j = 0; current_shape.shape[i][j] != '\0'; ++j) {
        if (current_shape.shape[i][j] == '*') {
            map[current_shape.offset.y + i][current_shape.offset.x + j +
            size.col / 2] = current_shape.color + '0';
        }
    }
}
