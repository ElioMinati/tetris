/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** print number passed as arg
*/

#include <stdlib.h>

char *my_int_to_str(int nb);

int my_strlen(char const *str);

void my_putchar(char c);

int my_putstr(char const *str);

void my_put_nbr(int nb)
{
    char *str = malloc (14 * sizeof(char));

    str = my_int_to_str(nb);
    my_putstr(str);
}

void my_put_nbr2(int nb, int format)
{
    char *str = malloc (14 * sizeof(char));

    str = my_int_to_str(nb);
    for (int i = 0; format - i > my_strlen(str); i++)
        my_putchar('0');
    my_putstr(str);
}
