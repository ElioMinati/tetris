/*
** EPITECH PROJECT, 2022
** rotation.c
** File description:
** do a piece rotation
*/

#include <stdlib.h>
#include "tetris.h"
#include "my.h"

void detect_rotation(tetris_t *game, int key)
{
    int j = 0;
    shape_t rotated_shape;

    if (key == game->key_turn) {
        rotated_shape.color = game->current_shape.color;
        rotated_shape.height = game->current_shape.height;
        rotated_shape.width = game->current_shape.width;
        rotated_shape.offset.x = game->current_shape.offset.x;
        rotated_shape.offset.y = game->current_shape.offset.y;
        rotated_shape.shape = malloc((my_arrlen(game->current_shape.shape)
        + 1) * sizeof(char *));
        for (int i = (my_arrlen(game->current_shape.shape) - 1); i >= 0; --i) {
            rotated_shape.shape[j] = malloc((
            my_strlen(game->current_shape.shape[i]) + 1) * sizeof(char));
            rotated_shape.shape[j] = my_revstr(game->current_shape.shape[i]);
            ++j;
        }
        rotated_shape.shape[my_arrlen(game->current_shape.shape)] = NULL;
        game->current_shape = rotated_shape;
    }
}
