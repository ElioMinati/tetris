/*
** EPITECH PROJECT, 2022
** display_game.c
** File description:
** functions used for game display
*/

#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include "tetris.h"

static void display_grid(tetris_t *game)
{
    int i = 0;
    int j;

    mvprintw(0, 29, "%c", '+');
    for (j = 30; j < (30 + game->map.col + 1); ++j)
        mvprintw(i, j, "%c", '-');
    mvprintw(0, j, "%c\n", '+');
    for (i = 1; i < (game->map.row + 1); ++i) {
        mvprintw(i, 29, "%c", '|');
        for (j = 30; j < (30 + game->map.col + 1); ++j)
            mvprintw(i, j, "%c", ' ');
        mvprintw(i, j, "%c\n", '|');
    }
    mvprintw(i, 29, "%c", '+');
    for (j = 30; j < (30 + game->map.col + 1); ++j)
        mvprintw(i, j, "%c", '-');
    mvprintw(i, j, "%c\n", '+');
}

static void display_next(tetris_t *game)
{
    int i;
    int j;

    mvprintw(0, 30 + game->map.col + 5, "%s", "/-next");
    for (i = 30 + game->map.col + 6 + 5; i <
    (game->map.col + 30 + 6 + 5 + 4); ++i)
        mvprintw(0, i, "%c", '-');
    mvprintw(0, i, "%c\n", '\\');
    for (j = 1; j < 5; ++j) {
        mvprintw(j, 30 + game->map.col + 5, "%c", '|');
        for (i = game->map.col + 5 + 1 + 30; i <
        (game->map.col + 5 + 6 + 4 + 30); ++i);
        mvprintw(j, i, "%c\n", '|');
    }
    mvprintw(5, 30 + game->map.col + 5, "%c", '\\');
    for (i = 30 + game->map.col + 1 + 5; i <
    (30 + game->map.col + 6 + 5 + 4); ++i)
        mvprintw(5, i, "%c", '-');
    mvprintw(5, i, "%c\n", '/');
    display_next_shape(game->next_shape, game->map.col);
}

static void display_info_box(void)
{
    int i;

    mvprintw(5, 0, "%s", "/--------------------------\\");
    for (i = 6; i < 15; ++i)
        mvprintw(i, 0, "%s", "|                          |");
    mvprintw(i, 0, "%s", "\\--------------------------/");
}

void display_map(char **map)
{
    for (int i = 0; map[i] != NULL; ++i) {
        for (int j = 0; map[i][j] != '\0'; ++j) {
            attron(COLOR_PAIR(map[i][j] - '0'));
            mvprintw(1 + i, 30 + j, "%c", '*');
            attroff(COLOR_PAIR(map[i][j] - '0'));
        }
    }
}

void display_game(tetris_t *game, int key)
{
    display_info_box();
    display_game_info(game);
    display_grid(game);
    if (game->without_next == FALSE)
        display_next(game);
    display_map(game->all_shapes);
    detect_loss(game);
    if (game->is_lost == 0) {
        detect_rotation(game, key);
        detect_down(game, key);
        display_shape(game, key);
        detect_full_line(game->all_shapes, game);
    }
}
