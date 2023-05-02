/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** functions used to initialize tetris
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"
#include "tetris.h"

void init_colors(void)
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
}

static void init_shapes(tetris_t *game)
{
    int i;
    char **files = get_tetrimino_files();
    char **filecontent = get_tetrimino_content(files);

    game->shapes = malloc((my_arrlen(filecontent) + 1) * sizeof(shape_t));
    game->shapes->current_shape = -1;
    game->shapes->nb_shapes = my_arrlen(filecontent);
    for (i = 0; filecontent[i] != NULL; ++i) {
        game->shapes[i].height = get_shape_height(filecontent[i]);
        game->shapes[i].width = get_shape_width(filecontent[i]);
        game->shapes[i].color = get_shape_color(filecontent[i]);
        game->shapes[i].shape = get_shape(filecontent[i]);
    }
    game->elapsed_time = 0;
    game->all_shapes = init_map(game);
    game->max_col_height = malloc(game->map.col * sizeof(int));
    for (int i = 0; i < game->map.col; ++i)
        game->max_col_height[i] = game->map.row;
    init_current_shape(game);
}

void init_game(int ac, char **av, tetris_t *game)
{
    game->start_level = 1;
    game->key_left = KEY_LEFT;
    game->key_right = KEY_RIGHT;
    game->key_turn = KEY_UP;
    game->key_drop = KEY_DOWN;
    game->key_quit = 'q';
    game->key_pause = 'p';
    game->map.row = 20;
    game->map.col = 10;
    game->without_next = FALSE;
    game->debug = FALSE;
    game->clock = clock();
    for (int i = 1; i < ac; ++i) {
        param_handler(ac, av, game);
    }
    init_shapes(game);
}
