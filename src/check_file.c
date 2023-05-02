/*
** EPITECH PROJECT, 2022
** check_file.c
** File description:
** functions to verify the validity of a file
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int is_valid_file(char *str)
{
    char *buf = malloc(my_strlen(str) * sizeof(char));

    buf = my_strcpy(buf, str);
    if (buf == NULL)
        return 0;
    for (int i = 0; i < 3; ++i) {
        if (my_getnbr(buf) == -1) {
            return 0;
        }
        for (; buf[0] != ' ' && buf[0] != '\n'; buf++);
        buf++;
    }
    for (int i = 0; buf[i] != '\0'; ++i) {
        if (buf[i] != '*' && buf[i] != ' ' && buf[i] != '\n')
            return 0;
    }
    return 1;
}
