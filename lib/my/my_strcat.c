/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** concatenates two strings
*/

#include "my.h"

char *my_strcat(char *str1, char *str2)
{
    for (int i = 0; str2[i]; i++)
        str1 = add_in_str(str1, str2[i]);
    return (str1);
}
