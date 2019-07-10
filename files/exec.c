/*
** EPITECH PROJECT, 2019
** exec.c
** File description:
** Functions for execute command
*/

#include "my.h"

void do_exec(struct my_sh *s_sh)
{
    char **arg = word_array(s_sh->sep->cmd, ' ');

    if (s_sh->sep->type == 1 || s_sh->sep->type == 42 || s_sh->sep->type == 0)
        simple_exec(s_sh);
    if (s_sh->sep->type == 3)
        write_in_file(s_sh, s_sh->sep->cmd, s_sh->sep->next_cmd, 0);
    if (s_sh->sep->type == 5)
        write_in_file(s_sh, s_sh->sep->cmd, s_sh->sep->next_cmd, 1);
    if (s_sh->sep->type == 4)
        write_in_file(s_sh, s_sh->sep->next_cmd, s_sh->sep->cmd, 0);
    if (s_sh->sep->type == 5)
        write_in_file(s_sh, s_sh->sep->next_cmd, s_sh->sep->cmd, 1);
    if (s_sh->sep->type == 2)
        manage_pipe(s_sh);
}

void execution(struct my_sh *s_sh)
{
    int status;
    int e = 0;
    pid_t pid = fork();

    if (pid == -1)
        perror("pid\n");
    if (pid == 0) {
        do_exec(s_sh);
    } else {
        wait(&status);
        if (WTERMSIG(status) == 11)
            my_printf("Segmentation fault\n"), e = 1;
        if (WTERMSIG(status) == 139)
            my_printf("Segmentation fault (core dumped)\n"), e = 1;
        if (WTERMSIG(status) == 136)
            my_printf("Floating point exception (core dumped)\n"), e = 1;
        if (WTERMSIG(status) == 8)
            my_printf("Floating point exception\n"), e = 1;
        s_sh->return_val = WTERMSIG(status);
    }
}

int my_exec(struct my_sh *s_sh)
{
    char *path = NULL;
    char *path_env = get_env(s_sh->env, "PATH");

    if (s_sh->sep->type == 42) {
        if (same_start(s_sh->sep->cmd, "./"))
            path = get_path_file_exec(s_sh->sep->cmd);
        else
            path = find_files(path_env, word_array(s_sh->sep->cmd, ' ')[0]);
        if (!path) {
            my_printf("%s: Command not found.\n", s_sh->sep->cmd);
            s_sh->return_val = 1;
            return (0);
        }
    }
    execution(s_sh);
}