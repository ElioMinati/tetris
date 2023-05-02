/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** debug
*/

#include "tetris.h"
#include "my.h"

void debug_mode1(tetris_t *tetris)
{
    char *col = my_revstr(my_int_to_str(tetris->map.col));
    char *row = my_revstr(my_int_to_str(tetris->map.row));

    if (tetris->without_next == true) {
        my_printf("Next : No\n");
    } else {
        my_printf("next: Yes\n");
    }
    my_printf("Level: %i\n", tetris->start_level);
    my_printf("Size: %s*%s\n\n", row, col);
    display_tetri();
}

void debug_mode2(tetris_t *tetris)
{
    char *d = rst(its(tetris->key_drop));
    char *q = rst(its(tetris->key_quit));
    char *p = rst(its(tetris->key_pause));
    char *t = rst(its(tetris->key_turn));

    if (tetris->key_turn == 259) {
        my_printf("Key turn: KEY_UP (%s)\n", "259");
    } else {
        my_printf("Key turn: %c (%s)\n", tetris->key_turn, t);
    }
    if (tetris->key_drop == 258) {
        my_printf("Key drop: KEY_DOWN (%s)\n", "258");
    } else {
        my_printf("Key drop: %c (%s)\n", tetris->key_drop, d);
    }
    my_printf("Key quit: %c (%s)\n", tetris->key_quit, q);
    my_printf("Key pause: %c (%s)\n", tetris->key_pause, p);
    debug_mode1(tetris);
}

void debug_mode(tetris_t *tetris)
{
    char *l = rst(its(tetris->key_left));
    char *r = rst(its(tetris->key_right));

    if (tetris->key_left == 260) {
        my_printf("Key left: KEY_LEFT (260)\n");
    } else {
        my_printf("Key left: %c (%s)\n", tetris->key_left, l);
    }
    if (tetris->key_right == 261) {
        my_printf("Key right: KEY_RIGHT (%s)\n", "261");
    } else {
        my_printf("Key right: %c (%i)\n", tetris->key_right, r);
    }
    debug_mode2(tetris);
}
