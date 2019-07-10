/*
** EPITECH PROJECT, 2019
** exec_file.c
** File description:
** Execution of file with ./
*/

#include "my.h"

int is_regular_file(char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

char *get_path_file_exec(char *cmd)
{
    char *new_cmd = NULL;

    for (int i = 2; cmd[i]; i++)
        new_cmd = add_in_str(new_cmd, cmd[i]);
    if (access(new_cmd, F_OK) != -1)
        return (new_cmd);
    return (NULL);
}

void exec_file(char *cmd, struct my_sh *s_sh)
{
    char *path = NULL;

    if (!cmd[2])
        my_printf("./: Permission denied.\n");
    else {
        path = get_path_file_exec(cmd);
        if (!path)
            my_printf("%s: Command not found.\n", cmd);
        else if (!is_regular_file(path))
            my_printf("%s: Permission denied.\n", cmd);
        else
            my_exec(s_sh);
    }
}