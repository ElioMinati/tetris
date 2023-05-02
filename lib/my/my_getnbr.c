/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** get nbr
*/

#include "../../include/my.h"

static int is_nb_in_str(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (my_is_num_char(str[i]) == 1)
            return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int number = 0;
    int neg = 1;

    if (is_nb_in_str(str) == 0) {
        return -1;
    }
    while (str[i] != '\n' && my_is_num_char(str[i]) == 0) {
        ++i;
    }
    while (str[i] != '\n' && my_is_num_char(str[i]) == 1) {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return (number * neg);
}
