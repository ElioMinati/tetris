/*
** EPITECH PROJECT, 2022
** init_map.c
** File description:
** functions used to initialize the char ** used to store pieces
*/

#include <stdlib.h>
#include "tetris.h"

void init_current_shape(tetris_t *game)
{
    int randint = rand() % (game->shapes->nb_shapes);

    game->next_shape.color = game->shapes[randint].color;
    game->next_shape.height = game->shapes[randint].height;
    game->next_shape.width = game->shapes[randint].width;
    game->next_shape.shape = game->shapes[randint].shape;
    game->next_shape.offset.x = 0;
    game->next_shape.offset.y = 0;
    game->is_lost = 0;
    game->score = 0;
    game->level = 1;
}

char **init_map(tetris_t *tetris)
{
    int i;
    int j;
    char **map = malloc((tetris->map.row + 1) * sizeof(char *));

    for (i = 0; i < tetris->map.row; ++i) {
        map[i] = malloc((tetris->map.col + 1) * sizeof(char));
        for (j = 0; j < (tetris->map.col + 1); ++j)
            map[i][j] = ' ';
        map[i][j] = '\0';
    }
    map[i] = NULL;
    return map;
}
