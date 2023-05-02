/*
** EPITECH PROJECT, 2022
** detect_loss.c
** File description:
** functions used to detect loss
*/

#include "tetris.h"

static void detect_space(tetris_t *game, int i, int j)
{
    if (game->all_shapes[i][j] != ' ')
        game->is_lost = 1;
}

void detect_loss(tetris_t *game)
{
    for (int i = 0; i < game->current_shape.height; ++i) {
        for (int j = 0; game->all_shapes[i][j] != '\0'; ++j) {
            detect_space(game, i, j);
        }
    }
}
