/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** echo.c
*/

#include "my.h"

int print_spe_char(char *str, int i)
{
    int found = 0;

    if (str[i + 1] == 'v')
        my_putchar(11), i++, found = 1;
    if (str[i + 1] == 'n' && found == 0)
        my_putchar(10), i++, found = 1;
    if (str[i + 1] == 't' && found == 0)
        my_putchar(9), i++, found = 1;
    if (str[i + 1] == 'a' && found == 0)
        my_putchar(7), i++, found = 1;
    if (str[i + 1] == 'b' && found == 0)
        my_putchar(8), i++, found = 1;
    if (str[i + 1] == 'e' && found == 0)
        my_putchar(27), i++, found = 1;
    if (str[i + 1] == 'f' && found == 0)
        my_putchar(12), i++, found = 1;
    if (str[i + 1] == 'r' && found == 0)
        my_putchar(13), i++, found = 1;
    return (i);
}

void my_putstr_echo(char *str)
{
    int size = strlen(str);

    for (int i = 0; i < size; i++)
        if (str[i] == 92)
            i = print_spe_char(str, i);
        else
            my_putchar(str[i]);
    my_putchar(10);
}

void manage_flag_echo(char **buffer)
{
    if (buffer[1][1] == 'n')
        my_printf("%s", buffer[2]);
    if (buffer[1][1] == 'e')
        my_putstr_echo(buffer[2]);
}

int my_echo(char *line, struct my_sh *sh)
{
    char **buffer = word_array(line, ' ');

    if (buffer[1] == NULL)
        return (1);
    if (!strcmp(buffer[1], "$?") == 1)
        my_printf("%d\n", sh->return_val);
    else if (buffer[1][0] == '-')
        manage_flag_echo(buffer);
    else {
        for (int i = 1; buffer[i]; i++)
            my_printf("%s ", buffer[i]);
        my_printf("\n");
    }
}