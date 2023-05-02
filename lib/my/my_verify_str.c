/*
** EPITECH PROJECT, 2022
** verify_str
** File description:
** verify is an str is a number or not
*/

#include <unistd.h>
#include "my.h"

int my_is_num_char(char c);

int verify_is_str_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_is_num_char(str[i]) == 1 || str[i] == '-' || str[i] == '.')
            continue;
        else
            return 1;
    }
    return 0;
}

static void modif_str(char **arr, int i)
{
    for (int j = my_strlen(arr[i]) - 1; j >= 0; --j) {
        if (arr[i][j] == ' ')
            arr[i][j] = '\0';
        else
            break;
    }
}

void del_end_space(char **arr)
{
    for (int i = 0; arr[i] != NULL; ++i) {
        modif_str(arr, i);
    }
}
