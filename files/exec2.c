/*
** EPITECH PROJECT, 2019
** exec2.c
** File description:
** Functions for execute command
*/

#include "my.h"

int write_in_file(struct my_sh *s_sh, char *ne, char *nf, int write_end)
{
    int fd;
    char **arg = word_array(ne, ' ');
    char *struct_path;
    char *my_exec = word_array(ne, ' ')[0];

    if (!write_end)
        fd = open(nf, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    else
        fd = open(nf, O_CREAT | O_WRONLY | O_APPEND, 0600);
    struct_path = find_files(get_env(s_sh->env, "PATH"), my_exec);
    dup2(fd, 1);
    close(fd);
    execve(struct_path, arg, s_sh->env);
}

void dup2_pipe(char ***cmd, struct my_sh *s_sh, int fd[3], char *path)
{
    FILE* file;

    dup2(fd[2], 0);
    if (*(cmd + 1) != NULL) {
        if (s_sh->sep->type == 3 || s_sh->sep->type == 5) {
            if (s_sh->sep->type == 3)
                file = fopen(s_sh->sep->next_cmd, "w");
            else
                file = fopen(s_sh->sep->next_cmd, "w+");
            dup2(fileno(file), fileno(stdout));
            fclose(file);
        } else
            dup2(fd[1], 1);
    }
    close(fd[0]);
    if (!path)
        my_printf("%s: Command not found.\n", (*cmd)[0]);
    else if (!manage_cmd(s_sh->sep->cmd, s_sh, 1))
        execvp((*cmd)[0], *cmd);
}

void exec_pipe(char ***cmd, struct my_sh *s_sh)
{
    int fd[2];
    pid_t pid;
    int fd_actu = 0;
    char *path = NULL;
    char *get_path = get_env(s_sh->env, "PATH");

    while (*cmd != NULL) {
        pipe(fd);
        path = find_files(get_path, word_array((*cmd)[0], ' ')[0]);
        pid = fork();
        if (pid == -1)
            perror("fork"), exit(1);
        else if (pid == 0) {
            dup2_pipe(cmd, s_sh, (int [3]){fd[0], fd[1], fd_actu}, path);
            exit(1);
        } else
            wait(NULL), close(fd[1]), fd_actu = fd[0], cmd++;
    }
    exit(0);
}

void manage_pipe(struct my_sh *s_sh)
{
    char ***cmd = NULL;
    char **get_exec = NULL;
    struct my_sh *sh_init = s_sh;

    while (s_sh->sep->type == 2) {
        cmd = dd_str(cmd, word_array(s_sh->sep->cmd, ' '));
        s_sh->sep = s_sh->sep->next;
    }
    cmd = dd_str(cmd, word_array(s_sh->sep->cmd, ' '));
    exec_pipe(cmd, s_sh);
}

void simple_exec(struct my_sh *s_sh)
{
    char *path = NULL;
    char *all_path = get_env(s_sh->env, "PATH");

    if (same_start(s_sh->sep->cmd, "./"))
        path = get_path_file_exec(s_sh->sep->cmd);
    else
        path = find_files(all_path, word_array(s_sh->sep->cmd, ' ')[0]);
    execve(path, word_array(s_sh->sep->cmd, ' '), s_sh->env);
}