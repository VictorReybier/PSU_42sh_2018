/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** unsetenv.c
*/

#include "my.h"

void remove_env(char **rl_cmd, int nb, int i, struct my_sh *s_sh)
{
    if (str_hard_cmp(rl_cmd[nb], s_sh->env[i]) == 1)
        for (int j = i; s_sh->env[j]; ++j)
            s_sh->env[j] = s_sh->env[j + 1];
}

void my_unsetenv(char *cmd, struct my_sh *s_sh)
{
    char **rl_cmd = word_array(cmd, ' ');

    if (!s_sh->env[0])
        return;
    if (cnt_space(cmd) == 0) {
        my_printf("unsetenv: Too few arguments.");
        return;
    }
    for (int nb = 1; rl_cmd[nb]; ++nb)
        for (int i = 1; s_sh->env[i]; ++i)
            remove_env(rl_cmd, nb, i, s_sh);
}