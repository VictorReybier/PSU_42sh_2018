/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main of 42sh
*/

#include "my.h"

int manage_cmd2(char *cmd, struct my_sh *s_sh)
{
    int find = 0;

    if (!strcmp(word_array(cmd, ' ')[0], "exit"))
        manage_exit(cmd), find = 1;
    if (!strcmp(word_array(cmd, ' ')[0], "alias"))
        manage_alias(cmd, s_sh), find = 1;
    if (same_start(cmd, "./"))
        s_sh->sep->cmd = cmd, exec_file(cmd, s_sh), find = 1;
    if (!find)
        return (0);
    return (1);
}

int manage_cmd(char *cmd, struct my_sh *s_sh, int nb)
{
    int find = 0;

    if (!nb && find_char(cmd, '|'))
        return (0);
    if (!strcmp(word_array(cmd, ' ')[0], "echo"))
        my_echo(cmd, s_sh), find = 1;
    if (!strcmp(cmd, "env"))
        display_env(s_sh->env), find = 1;
    if (!strcmp(word_array(cmd, ' ')[0], "setenv"))
        my_setenv(cmd, s_sh), find = 1;
    if (!strcmp(word_array(cmd, ' ')[0], "unsetenv"))
        my_unsetenv(cmd, s_sh), find = 1;
    if (!strcmp(word_array(cmd, ' ')[0], "cd"))
        change_dir(word_array(cmd, ' '), s_sh), find = 1;
    if (manage_cmd2(cmd, s_sh))
        find = 1;
    if (!find)
        return (0);
    return (1);
}

char *get_folder(char **env)
{
    char **n_path;
    int nb_arg = 0;
    char *path;

    path = (char *)malloc(100*sizeof(char));
    getcwd(path, 100);
    n_path = word_array(path, '/');
    for (; n_path[nb_arg]; nb_arg++);

    return (n_path[--nb_arg]);
}

void run_sh(struct my_sh *s_sh)
{
    char *line = NULL;
    size_t len = 0;
    struct sep *sep_init = s_sh->sep;

    while (1) {
        s_sh->sep = malloc(sizeof(struct sep));
        s_sh->sep->next = NULL;
        my_printf("\e[1;32m[%s] $> \e[0m", get_folder(s_sh->env));
        if (getline(&line, &len, stdin) == -1)
            my_printf("exit\n"), exit(0);
        line = rmv_par(remove_space(rmv_entry(line)));
        if (check_alias(line, s_sh))
            line = check_alias(line, s_sh);
        if (!manage_cmd(line, s_sh, 0) && line[0] != 10 && line[0])
            fill_separator(line, s_sh);
        s_sh->sep = sep_init;
    }
}

int main(int ac, char **av, char **env)
{
    struct my_sh *s_sh = malloc(sizeof(struct my_sh));

    s_sh->env = env;
    s_sh->return_val = 0;
    s_sh->alias = NULL;
    s_sh->oldpwd = NULL;
    if (env[0] == NULL)
        create_env(s_sh);
    run_sh(s_sh);
    return (0);
}
