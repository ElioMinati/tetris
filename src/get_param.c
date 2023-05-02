/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** get_param
*/

#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "my.h"
#include "tetris.h"

void get_param4(int c, tetris_t *tetris)
{
    switch(c) {
        case 'm':
            char **temp = jl_staw(optarg, ',');
            tetris->map.row = my_getnbr(temp[0]);
            tetris->map.col = my_getnbr(temp[1]);
            break;
    }
}

void get_param3(char **av, int c, tetris_t *tetris)
{
    switch(c) {
        case 'w':
            if (my_strlen(av[optind - 1]) <= 2) {
                tetris->without_next = true;
            } else {
                tetris->without_next = true;
            }
            break;
        case 'D':
            if (my_strlen(av[optind - 1]) <= 2) {
                tetris->debug = true;
            } else {
                tetris->debug = true;
            }
            break;
    }
    get_param4(c, tetris);
}

void get_param2(char **av, int c, tetris_t *tetris)
{
    switch(c) {
        case 'q':
            if (my_strlen(av[optind - 1]) <= 2) {
                tetris->key_quit = my_getnbr(av[optind]);
            } else {
                tetris->key_quit = my_getnbr(optarg);
            }
            break;
        case 'L':
            if (my_strlen(av[optind - 1]) <= 2) {
                tetris->start_level = my_getnbr(av[optind]);
            } else {
                tetris->start_level = my_getnbr(optarg);
            }
            break;
    }
    get_param3(av, c, tetris);
}

void get_param1(char **av, int c, tetris_t *tetris)
{
    switch(c) {
        case 't':
            if (my_strlen(av[optind - 1]) <= 2) {
                tetris->key_turn = my_getnbr(av[optind]);
            } else {
                tetris->key_turn = my_getnbr(optarg);
            }
            break;
        case 'q':
            if (my_strlen(av[optind - 1]) <= 2) {
                tetris->key_quit = my_getnbr(av[optind]);
            } else {
                tetris->key_quit = my_getnbr(optarg);
            }
            break;
    }
    get_param2(av, c, tetris);
}

void get_param(char **av, int c, tetris_t *tetris)
{
    switch(c) {
        case 'l':
            if (my_strlen(av[optind - 1]) <= 2) {
                tetris->key_left = my_getnbr(av[optind]);
            } else {
                tetris->key_left = my_getnbr(optarg);
            }
            break;
        case 'r':
            if (my_strlen(av[optind - 1]) <= 2) {
                tetris->key_right = my_getnbr(av[optind]);
            } else {
                tetris->key_right = my_getnbr(optarg);
            }
            break;
    }
    get_param1(av, c, tetris);
}
