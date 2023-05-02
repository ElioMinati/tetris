/*
** EPITECH PROJECT, 2022
** param_handler
** File description:
** handle all of tetris parameters
*/

#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include "my.h"
#include "tetris.h"

char *parsearg(char *str, int w)
{
    int x = my_strlen(str) - w;
    int m = 0;
    char *temp = malloc(sizeof(char) * x + 1);

    for (int j = 11; str[j] != '\0'; j++) {
        temp[m] = str[j];
        ++m;
    }
    return temp;
}

void param_handler(int ac, char **av, tetris_t *tetris)
{
    int c;
    int option_index = 0;
    const struct option long_options[] = {
        {"level", required_argument, 0, 'L'},
        {"key-left", required_argument, 0, 'l'},
        {"key-right", required_argument, 0, 'r'},
        {"key-turn", required_argument, 0, 't'},
        {"key-drop", required_argument, 0, 'd'},
        {"key-quit", required_argument, 0, 'q'},
        {"key-pause", required_argument, 0, 'p'},
        {"map-size", required_argument, 0, 'm'},
        {"without-netx", no_argument, 0, 'w'},
        {"debug", no_argument, 0, 'D'},
        {0, 0, 0, 0}
    };
    while (c != -1) {
        c = getopt_long(ac, av, "LlrtdqpwD", long_options, &option_index);
        get_param(av, c, tetris);
    }
}
