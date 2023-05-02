/*
** EPITECH PROJECT, 2022
** display_shape.c
** File description:
** functions used to display_shapes
*/

#include <ncurses.h>
#include <curses.h>
#include "tetris.h"

void display_tetrimino(shape_t shape, int col)
{
    attron(COLOR_PAIR(shape.color));
    for (int i = 1; shape.shape[i - 1] != NULL; ++i) {
        mvprintw(i + shape.offset.y, 30 + (col / 2) +
        shape.offset.x, "%s", shape.shape[i - 1]);
    }
    attroff(COLOR_PAIR(shape.color));
}

void display_next_shape(shape_t shape, int col)
{
    attron(COLOR_PAIR(shape.color));
    for (int i = 1; shape.shape[i - 1] != NULL; ++i) {
        mvprintw(i + shape.offset.y, 37 + col +
        shape.offset.x, "%s", shape.shape[i - 1]);
    }
    attroff(COLOR_PAIR(shape.color));
}
