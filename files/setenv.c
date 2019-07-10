/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** setenv.c
*/

#include "my.h"

void create_new_env(char **rl_cmd, struct my_sh *s_sh)
{
    int pos = 0;

    s_sh->env = push_array(s_sh->env, rl_cmd[1]);
    pos = my_arraylen(s_sh->env);
    for (int j = 0; j < strlen(rl_cmd[2]); ++j)
        s_sh->env[pos - 1] = add_in_str(s_sh->env[pos - 1], rl_cmd[2][j]);
}

void rewrite_env(char **rl_cmd, int i, struct my_sh *s_sh)
{
    int pos = strlen(rl_cmd[1]);

    s_sh->env[i] = "";
    for (int j = 0; j < strlen(rl_cmd[1]); ++j)
        s_sh->env[i] = add_in_str(s_sh->env[i], rl_cmd[1][j]);
    for (int j = 0; j < strlen(rl_cmd[2]); ++j)
        s_sh->env[i] = add_in_str(s_sh->env[i], rl_cmd[2][j]);
}

void do_env(char **rl_cmd, char *cmd, struct my_sh *s_sh)
{
    if (s_sh->env[0] == NULL && error_setenv(rl_cmd))
        s_sh->env = push_array(s_sh->env, rl_cmd[1]);
    if (cnt_space(cmd) == 1)
        for (int i = 0; s_sh->env[i]; ++i) {
            if (str_hard_cmp(rl_cmd[1], s_sh->env[i]) == 1) {
                s_sh->env[i][strlen(rl_cmd[1])] = '\0';
                break;
            }
            if (i == my_arraylen(s_sh->env) - 1)
                s_sh->env = push_array(s_sh->env, rl_cmd[1]);
        }
    if (cnt_space(cmd) == 2)
        for (int i = 0; s_sh->env[i]; ++i)
            if (str_hard_cmp(rl_cmd[1], s_sh->env[i]) == 1) {
                rewrite_env(rl_cmd, i, s_sh);
                break;
            } else if (i == my_arraylen(s_sh->env) - 1)
                create_new_env(rl_cmd, s_sh);
}

int error_setenv(char **rl_cmd)
{
    if (IS_BAD_START(rl_cmd[1][0])) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    for (int i = 1; rl_cmd[i]; ++i)
        for (int j = 0; rl_cmd[i][j]; ++j)
            if (IS_NO_ALPHA(rl_cmd[i][j])) {
                my_printf("setenv: Variable name must contain");
                my_printf(" alphanumeric characters.\n");
                return (84);
            }
    return (0);
}

void my_setenv(char *cmd, struct my_sh *s_sh)
{
    char **rl_cmd = word_array(cmd, ' ');
    int cnt = 6;


    for (; cmd[cnt] == ' '; ++cnt);
    if (rl_cmd[0][strlen(rl_cmd[0]) - 1] == ' ')
        rl_cmd[0][strlen(rl_cmd[0]) - 1] = '\0';
    if (strlen(cmd) == cnt && str_hard_cmp(rl_cmd[0], "setenv") == 1) {
        display_env(s_sh->env);
        return;
    }
    if (error_setenv(rl_cmd) == 84)
        return;
    rl_cmd[1] = add_in_str(rl_cmd[1], '=');
    if (cnt_space(cmd) > 2)
        my_printf("setenv: Too many arguments.\n");
    do_env(rl_cmd, cmd, s_sh);
}