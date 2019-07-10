/*
** EPITECH PROJECT, 2019
** path.c
** File description:
** Function for manage path
*/

#include "my.h"

char *rmv_par(char *str)
{
    char *new_str = NULL;

    for (int i = 0; str[i]; i++)
        if (str[i] != '(' && str[i] != ')')
            new_str = add_in_str(new_str, str[i]);
    return (new_str);
}

int find_char(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

char *get_path(char *str)
{
    char *new_str = NULL;
    int start = 0;

    for (; str[start] != '='; start++);
    start++;
    for (int i = start; str[i]; i++)
        new_str = add_in_str(new_str, str[i]);
    return (new_str);
}

char *rmv_end_char(char *str)
{
    char *new_str = NULL;

    for (int i = 0; i < strlen(str) - 1; i++)
        new_str = add_in_str(new_str, str[i]);
    free(str);
    return (new_str);
}

char *rmv_entry(char *str)
{
    if (str[strlen(str) - 1] == '\n' && strlen(str) > 1)
        str = rmv_end_char(str);
    return (str);
}