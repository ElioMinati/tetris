/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** copy str to another on
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; i <= my_strlen(src); i++)
        dest[i] = src[i];
    return (dest);
}
