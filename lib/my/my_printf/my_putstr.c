/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Show a string
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

int my_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}

void print_error(char *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar_error(str[i]);
}
