/*
** EPITECH PROJECT, 2019
** mdf_dir
** File description:
** Change directory functionnality
*/

#include "my.h"

int go_back(struct my_sh *s_sh, char **env, char *array)
{
    int save;

    if (s_sh->oldpwd == NULL) {
        my_printf(": No such file or directory.\n");
        return (0);
    }
    for (int i = 0; env[i]; ++i)
        if (same_start(env[i], "PWD=") == 1)
            save = i;
    else {
        chdir(s_sh->oldpwd);
        env[save] = my_strcat("PWD=", s_sh->oldpwd);
    }
    return (0);
}

void chk_pwd(struct my_sh *s_sh, char **env, char **array, int check)
{
    int save;

    s_sh->oldpwd = srch_env(env, "PWD=");
    for (int i = 0; env[i]; ++i)
        if (same_start(env[i], "PWD=") == 1)
            save = i;
    if (check == 1)
        env[save] = my_strcat("PWD=", srch_env(env, "HOME="));
    else
        mdf_pwd(env, array, save);
}

int special_condi(char **array, struct my_sh *s_sh)
{
    if (array[2] != NULL) {
        my_printf("cd: Too many arguments.\n");
        return (0);
    }
    if (array[1] == NULL) {
        chdir(srch_env(s_sh->env, "HOME="));
        if (s_sh->env[0] != NULL)
            chk_pwd(s_sh, s_sh->env, array, 1);
        else
            my_printf("cd: No home directory.\n");
        return (0);
    }
    return (1);
}

int change_dir(char **array, struct my_sh *s_sh)
{
    struct stat sb;

    if (special_condi(array, s_sh) == 0)
        return (0);
    if (!strcmp("-", array[1])) {
        go_back(s_sh, s_sh->env, array[1]);
        return (0);
    }
    if (stat(array[1], &sb) == 0)
        if (S_ISDIR(sb.st_mode)) {
            chdir(array[1]);
            if (s_sh->env[0] != NULL)
                chk_pwd(s_sh, s_sh->env, word_array(array[1], '/'), 0);
        }
        else
            my_printf("%s: Not a directory.\n", array[1]);
    else
        my_printf("%s: No such file or directory.\n", array[1]);
    return (0);
}
