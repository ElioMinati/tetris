/*
** EPITECH PROJECT, 2022
** get_shape_attributes.c
** File description:
** grab attributes of shapes in their respective files
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "tetris.h"

char **get_tetrimino_content(char **path)
{
    int i;
    int j = 0;
    char **res = malloc(my_arrlen(path) * sizeof(char *));

    for (i = 0; path[i] != NULL; ++i, ++j) {
        res[j] = get_file_content(path[i]);
        if (is_valid_file(res[j]) == 0) {
            res[j] = NULL;
            j--;
        }
    }
    res[j] = NULL;
    return res;
}

int get_shape_width(char *str)
{
    return my_getnbr(str);
}

int get_shape_height(char *str)
{
    char *buf = malloc((my_strlen(str) + 1) * sizeof(char));

    buf = my_strcpy(buf, str);
    for (; buf[0] != ' '; buf++);
    return my_getnbr(buf);
}

int get_shape_color(char *str)
{
    char *buf = malloc((my_strlen(str) + 1) * sizeof(char));

    buf = my_strcpy(buf, str);
    for (; buf[0] != ' '; buf++);
    buf++;
    for (; buf[0] != ' '; buf++);
    return my_getnbr(buf);
}

char **get_shape(char *str)
{
    int j;
    int i;
    int lines = count_line_jumps(str);
    char **shape = malloc(lines * sizeof(char *));
    char *temp = malloc((my_strlen(str) + 1) * sizeof(char));

    for (; str[0] != '\n'; str++);
    str++;
    for (i = 0; i < lines; ++i) {
        for (j = 0; str[j] != '\n' && str[j] != '\0'; ++j) {
            temp[j] = str[j];
        }
        temp[j] = '\0';
        shape[i] = temp;
        for (; str[0] != '\n'; str++);
        str++;
        temp = malloc((my_strlen(str) + 1) * sizeof(char));
    }
    shape[i] = NULL;
    return shape;
}
