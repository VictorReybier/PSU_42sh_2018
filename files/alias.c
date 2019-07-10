/*
** EPITECH PROJECT, 2019
** alias.c
** File description:
** Create alias
*/

#include "my.h"

char *check_alias(char *line, struct my_sh *s_sh)
{
    char *str = NULL;

    if (s_sh->alias) {
        for (int i = 0; s_sh->alias[i]; i++) {
            if (!strcmp(s_sh->alias[i][0], line))
                for (int j = 1; s_sh->alias[i][j]; j++)
                    str = my_strcat(my_strcat(str, " "), s_sh->alias[i][j]);
        }
    }
    return (str);
}

void manage_alias(char *line, struct my_sh *s_sh)
{
    char *new_str = NULL;
    char **cut_str = word_array(line, ' ');
    char **end_str = NULL;
    int nb_arg = 0;

    for (; cut_str[nb_arg]; nb_arg++);
    if (nb_arg == 1)
        return;
    new_str = my_strcat(new_str, cut_str[1]);
    for (int i = 2; i < nb_arg; i++)
        new_str = my_strcat(my_strcat(new_str, " "), cut_str[i]);
    end_str = word_array(new_str, ' ');
    s_sh->alias = dd_str(s_sh->alias, end_str);
}