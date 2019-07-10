/*
** EPITECH PROJECT, 2019
** exit.c
** File description:
** Function for exit
*/

#include "my.h"

int manage_exit(char *cmd)
{
    int nb_arg = 0;
    int nb_return = 0;
    char **n_buffer = word_array(cmd, ' ');

    for (; n_buffer[nb_arg]; nb_arg++);
    if (nb_arg > 2)
        my_printf("exit: Expression Syntax.\n");
    else if (nb_arg == 1)
        exit(0);
    else
        for (int j = 0; n_buffer[1][j]; j++) {
            if (!IS_NUM(n_buffer[1][j])) {
                my_printf("exit: Expression Syntax.\n");
                return (0);
            }
        }
    my_printf("exit\n");
    nb_return = atoi(n_buffer[1]);
    exit(nb_return);
}