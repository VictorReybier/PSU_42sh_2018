/*
** EPITECH PROJECT, 2019
** chg_pwd
** File description:
** change the pwd in env
*/

#include "my.h"

void rmv_pwd(char **env, int save)
{
    for (int i = strlen(env[save]); env[save][i - 1] != '/'; --i)
        if (same_start(env[save], "PWD=/"))
            env[save] = my_realloc(env[save], strlen(env[save]) - 1);
    if (same_start(env[save], "PWD=/"))
        env[save] = my_realloc(env[save], strlen(env[save]) - 1);
    env[save][4] = '/';
}

void mdf_pwd(char **env, char **array, int save)
{
    for (int i = 0; array[i]; ++i) {
        if (same_start("/", array[i])) {
            env[save] = "PWD=/";
            break;
        }
        if (same_start(array[i], "..") == 0) {
            if (strlen(env[save]) != 5)
                env[save] = add_in_str(env[save], '/');
            env[save] = my_strcat(env[save], array[i]);
        }
        else
            rmv_pwd(env, save);
    }
}
