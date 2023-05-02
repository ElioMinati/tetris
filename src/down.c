/*
** EPITECH PROJECT, 2022
** down.c
** File description:
** functions to detect if piece is directly placed
*/

#include "tetris.h"

void detect_down(tetris_t *game, int key)
{
    if (key == game->key_drop) {
        while (is_done(game, game->all_shapes, game->map) == 0)
            ++game->current_shape.offset.y;
    }
}
