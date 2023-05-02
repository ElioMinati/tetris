/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** display_tetri
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

void display_tetri1(char *file, char *temp)
{
    char **tempo = jl_staw(file, '.');
    char **n = jl_staw(tempo[0], '/');
    int i = 0;
    int w = get_shape_width(temp);
    int h = get_shape_height(temp);
    int c = get_shape_color(temp);
    char **shape = get_shape(temp);

    my_printf("Tetriminos '%s': size %i*%i, color %i\n", n[1], w, h, c);
    del_end_space(shape);
    for (; shape[i] != NULL; ++i) {
        my_putstr(shape[i]);
        my_putchar('\n');
    }
    free(tempo);
    free(n);
}

void display_tetri3(char *file)
{
    char **tempo = jl_staw(file, '.');
    char **name = jl_staw(tempo[0], '/');

    my_printf("Tetriminos '%s': error\n", name[1]);
    free(tempo);
    free(name);
}

void check_file_correction(char *list, char *temp)
{
    if (is_valid_file(temp) == 0) {
        display_tetri3(list);
    } else {
        display_tetri1(list, temp);
    }
}

void display_tetri2(void)
{
    char **list = get_tetrimino_files();
    char *temp;
    int x = 0;

    for (;list[x] != NULL; ++x);
    my_printf("Number of tetriminos: %i\n", x);
    for (int i = 0; list[i] != NULL; ++i) {
        temp = get_file_content(list[i]);
        check_file_correction(list[i], temp);
    }
}

void display_tetri(void)
{
    display_tetri2();
}
