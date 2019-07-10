/*
** EPITECH PROJECT, 2019
** in_env.c
** File description:
** Function for manage env
*/

#include "my.h"

char *get_env(char **env, char *search)
{
    for (int j = 0; env[j]; j++)
        if (!strcmp(word_array(env[j], '=')[0], search))
            return (get_path(env[j]));
    return ("None");
}