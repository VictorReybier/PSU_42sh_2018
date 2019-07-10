/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** count_nb_spaces.c
*/

#include "my.h"

int cnt_space(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; ++i)
        if (str[i] == ' ')
            ++count;
    return (count);
}