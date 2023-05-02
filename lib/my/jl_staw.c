/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** jl_staw
*/

#include <stdlib.h>

int count_nb_words(char *str, char delim)
{
    int nb_words = 1;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == delim)
            ++nb_words;
    return nb_words;
}

char **jl_staw(char *src, char delim)
{
    int j = 0;
    int nb_words = count_nb_words(src, delim);
    char *str = src;
    char **array = malloc(sizeof(char) * (nb_words + 1));

    if (array == NULL)
        return NULL;
    for (int i = 0; i < nb_words; i++) {
        for (j = 0; str[j] != delim && str[j] != '\0'; j++);
        array[i] = malloc(sizeof(char) * (j + 1));
        if (array[i] == NULL)
            return NULL;
        for (j = 0; str[0] != delim && str[0] != '\0'; j++, (str)++)
            array[i][j] = str[0];
        array[i][j] = '\0';
        (str)++;
    }
    array[nb_words] = NULL;
    return array;
}