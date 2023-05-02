/*
** EPITECH PROJECT, 2022
** shape_drop.c
** File description:
** do_operations and display the drop of the shape
*/

#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include "tetris.h"
#include "my.h"

static void place_shape(shape_t current_shape, char **map, vector2i size)
{
    for (int i = 0; current_shape.shape[i] != NULL; ++i) {
        add_into_map(current_shape, i, map, size);
    }
}

int is_done(tetris_t *game, char **map, vector2i size)
{
    for (int i = 0; game->current_shape.shape[i] != NULL; ++i) {
        if (is_hit(game, map, i, size) == 1)
            return 1;
    }
    if ((game->current_shape.offset.y + game->current_shape.height) >
    (my_arrlen(map) - 1))
        return 1;
    return 0;
}

static void move_shape(tetris_t *game, int key)
{
    if (key == game->key_right && ((game->map.col / 2) +
    game->current_shape.offset.x) <=
    (game->map.col - game->current_shape.width))
        game->current_shape.offset.x += 1;
    if (key == game->key_left && ((game->map.col / 2)
    + game->current_shape.offset.x) > 0)
        game->current_shape.offset.x -= 1;
    if (is_done(game, game->all_shapes, game->map) == 1) {
        game->shapes->current_shape = -1;
        place_shape(game->current_shape, game->all_shapes, game->map);
    }
    game->clock = clock();
    if (game->current_shape.offset.y <
    (game->map.row - game->current_shape.height) &&
    ((game->clock - game->elapsed_time) > 3000)) {
        game->elapsed_time += 3000;
        game->current_shape.offset.y += 1;
    }
}

void display_shape(tetris_t *game, int key)
{
    int randint = rand() % (game->shapes->nb_shapes);

    if (game->shapes->current_shape == -1) {
        game->current_shape = game->next_shape;
        game->next_shape.color = game->shapes[randint].color;
        game->next_shape.height = game->shapes[randint].height;
        game->next_shape.width = game->shapes[randint].width;
        game->next_shape.shape = game->shapes[randint].shape;
        game->next_shape.offset.x = 0;
        game->next_shape.offset.y = 0;
        game->shapes->current_shape = randint;
    }

    display_tetrimino(game->current_shape, game->map.col);
    move_shape(game, key);
}
