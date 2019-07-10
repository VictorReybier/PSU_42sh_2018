/*
** EPITECH PROJECT, 2019
** cmd.c
** File description:
** Check binary files
*/

#include "my.h"

char *find_files(char *path, char *exec)
{
    char **n_path = word_array(path, ':');
    char *path_file = NULL;

    if (exec[0] == '/' && access(exec, F_OK) != -1)
        return (exec);
    for (int i = 0; n_path[i]; i++) {
        path_file = my_strcat(my_strcat(n_path[i], "/"), exec);
        if (access(path_file, F_OK) != -1)
            return (path_file);
        free(n_path[i]);
    }
    free(n_path);
    return (NULL);
}