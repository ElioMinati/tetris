/*
** EPITECH PROJECT, 2022
** tetris.c
** File description:
** start the tetris game
*/

#include <curses.h>
#include <sys/types.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"

void game_main(tetris_t *game)
{
    int key;

    while (key != game->key_quit && game->is_lost == 0) {
        display_game(game, key);
        key = getch();
        clear();
    }
    refresh();
    endwin();
}

void tetris(int ac, char **av)
{
    for (int i = 1; i < ac; ++i) {
        if (my_strcmp(av[i], "--help")) {
            display_help();
            return;
        }
    }
    tetris_t *game = malloc(sizeof(*game));
    srand(time(NULL));
    init_game(ac, av, game);
    if (game->debug == true) {
        debug_mode(game);
        return;
    }
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    timeout(50);
    curs_set(0);
    init_colors();
    game_main(game);
}
