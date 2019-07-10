/*
** EPITECH PROJECT, 2019
** search_env
** File description:
** search a value in environment
*/

#include "my.h"

char *srch_env(char **env, char *search)
{
    char *str = NULL;
    int save;

    if (env[0] == NULL)
        return (NULL);
    for (int i = 0; env[i]; ++i)
        if (same_start(env[i], search))
            save = i;
    for (int j = strlen(search); env[save][j]; ++j)
        str = add_in_str(str, env[save][j]);
    return (str);
}
