/*
** EPITECH PROJECT, 2019
** env.c
** File description:
** Functions for env
*/

#include "my.h"

void create_env(struct my_sh *s_sh)
{
    char *pwd;

    pwd = (char *)malloc(100*sizeof(char));
    getcwd(pwd, 100);
    s_sh->env = push_array(s_sh->env, my_strcat("PATH=", PATH_ENV));
    s_sh->env = push_array(s_sh->env, my_strcat("PWD=", pwd));
    s_sh->env = push_array(s_sh->env, "HOME=/");
}

void display_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        if (env[i][0])
            my_printf("%s\n", env[i]);
}