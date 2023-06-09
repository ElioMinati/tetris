/*
** EPITECH PROJECT, 2022
** help.c
** File description:
** display help
*/

#include "my.h"

void display_help(void)
{
    my_putstr("Usage: ./tetris [options]\n");
    my_putstr("Options:\n");
    my_putstr("  --help               Display this help\n");
    my_putstr("  -L --level={num}     Start Tetris at level num (def: 1)\n");
    my_putstr("  -l --key-left={K}    Move the tetrimino LEFT using the");
    my_putstr(" K key (def: left arrow)\n");
    my_putstr("  -r --key-right={K}   Move the tetrimino RIGHT using the");
    my_putstr(" K key (def: right arrow)\n");
    my_putstr("  -t --key-turn={K}    TURN the tetrimino clockwise 90d u");
    my_putstr("sing the K key (def: top arrow)\n");
    my_putstr("  -d --key-drop={K}    DROP the tetrimino using the K key");
    my_putstr(" (def: down arrow)\n");
    my_putstr("  -q --key-quit={K}    QUIT the game using the K key (def");
    my_putstr(": 'q' key)\n");
    my_putstr("  -p --key-pause={K}   PAUSE/RESTART the game using the K");
    my_putstr(" key (def: space bar)\n");
    my_putstr("  --map-size={row,col} Set the numbers of rows and columns");
    my_putstr(" of the map (def: 20,10)\n");
    my_putstr("  -w --without-next    Hide next tetrimino (def: false)\n");
    my_putstr("  -D --debug           Debug mode (def: false)\n");
}
