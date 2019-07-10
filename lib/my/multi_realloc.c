/*
** EPITECH PROJECT, 2019
** multi_realloc.c
** File description:
** Realloc char **
*/

#include "my.h"

void display_dd_str(char ***str)
{
    for (int i = 0; str[i]; i++) {
        for (int j = 0; str[i][j]; j++)
            my_printf("%s ", str[i][j]);
        my_printf("\n");
    }
}

int dd_strlen(char ***str)
{
    int my_len = 0;

    for (; str[my_len] != NULL; my_len++);
    return (my_len);
}

char ***my_ddrealloc(char ***str, int size)
{
    char ***new_str = malloc(sizeof(char **) * (size + 1));
    int i = 0;

    for (; str[i] && i < size; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';

    return (new_str);
}

char ***dd_str(char ***str, char **d_str)
{
    int size_str = 0;

    if (str == NULL) {
        str = malloc(sizeof(char **) * 2);
        str[0] = d_str;
        str[1] = NULL;
    } else {
        size_str = dd_strlen(str);
        str = my_ddrealloc(str, size_str + 1);
        str[size_str] = d_str;
        str[size_str + 1] = NULL;
    }

    return (str);
}