/*
** EPITECH PROJECT, 2022
** reverse string
** File description:
** function that reverses a string
*/

#include <stdlib.h>

int my_strlen(char const *str);

void my_revstr2(char *str)
{
    char *dest = malloc((my_strlen(str) + 1) * sizeof(char));

    for (int i = 0; i >= str[i] != '\0'; ++i)
        dest[i] = str[i];
    dest[my_strlen(str)] = '\0';
    for (int i = 0; i >= str[i] != '\0'; ++i)
        str[i] = dest[my_strlen(str) - 1 - i];
}

char *my_revstr(char *str)
{
    int j = 0;
    char *dest = malloc((my_strlen(str) + 1) * sizeof(char));

    for (int i = my_strlen(str) - 1; i >= 0; --i, ++j) {
        dest[j] = str[i];
    }
    dest[my_strlen(str)] = '\0';
    return dest;
}

char *rst(char *str)
{
    int j = 0;
    char *dest = malloc((my_strlen(str) + 1) * sizeof(char));

    for (int i = my_strlen(str) - 1; i >= 0; --i, ++j) {
        dest[j] = str[i];
    }
    dest[my_strlen(str)] = '\0';
    return dest;
}
