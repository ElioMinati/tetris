/*
** EPITECH PROJECT, 2022
** display_info.c
** File description:
** functions used to display some info in the info box
*/

#include <ncurses.h>
#include "tetris.h"

void display_game_info(tetris_t *game)
{
    double time = (double)(clock()) / CLOCKS_PER_SEC * 100;

    mvprintw(11, 5, "%s%i", "score: ", game->score);
    mvprintw(13, 5, "%s", "Time elapsed:");
    mvprintw(13, 20, "%.0f", time);
}
