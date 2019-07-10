/*
** EPITECH PROJECT, 2019
** my_realloc.c
** File description:
** Realloc
*/

#include "my.h"

void double_str_free(char **str)
{
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
}

char *my_realloc(char *str, int size)
{
    char *new_str = malloc(sizeof(char) * (size + 1));
    int i = 0;

    for (; str[i] && i < size; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';

    return (new_str);
}

char *add_in_str(char *str, char c)
{
    int size_str = 0;

    if (str == NULL) {
        str = malloc(sizeof(char) * 2);
        str[0] = c;
        str[1] = '\0';
    } else {
        size_str = strlen(str);
        str = my_realloc(str, size_str + 1);
        str[size_str] = c;
        str[size_str + 1] = '\0';
    }

    return (str);
}

char *add_two_str(char *str, char *str1)
{
    for (int i = 0; str1[i]; i++)
        str = add_in_str(str, str1[i]);
    return (str);
}
