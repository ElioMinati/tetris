/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** display one by one charachters of a string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb++;
    }
    return 0;
}

int my_putstr2(char const *str, int format)
{
    for (int i = 0; str[i] != '\0' && i < format; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
