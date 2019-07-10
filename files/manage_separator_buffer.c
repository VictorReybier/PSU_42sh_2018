/*
** EPITECH PROJECT, 2019
** manage_separator_buffer.c
** File description:
** Detect separator in buffer
*/

#include "my.h"

int gt(char *buffer, int pos)
{
    if (buffer[pos] == ';')
        return (1);
    if (buffer[pos] == '>')
        if (buffer[pos] && buffer[pos + 1] == '>')
            return (5);
        else
            return (3);
    if (buffer[pos] == '<')
        if (buffer[pos] && buffer[pos + 1] == '<')
            return (6);
        else
            return (4);
    if (buffer[pos] == '&' && buffer[pos + 1])
        if (buffer[pos] && buffer[pos + 1] == '&')
            return (7);
    if (buffer[pos] == '|' && buffer[pos + 1])
        if (buffer[pos] && buffer[pos + 1] == '|')
            return (8);
        else
            return (2);
    return (1);
}

void execute_all(struct my_sh *s_sh)
{
    struct my_sh *s_sh_init = s_sh;
    int nb = 0;

    for (; s_sh->sep != NULL; s_sh->sep = s_sh->sep->next) {
        my_exec(s_sh);
        if (s_sh->sep->type == 8)
            return;
        nb = s_sh->sep->type;
        if (nb != 1 && nb != 42 && nb != 7) {
            if (s_sh->sep->next != NULL)
                s_sh->sep = s_sh->sep->next;
        }
    }
}

char *get_next_cmd(char *buffer, char *s_c, int start)
{
    char *str = NULL;

    for (int i = 0; buffer[i]; i++)
        for (int j = 0; s_c[j]; j++)
            if (buffer[i] == s_c[j])
                start++;
    for (int i = start; buffer[i]; i++) {
        str = add_in_str(str, buffer[i]);
        for (int j = 0; s_c[j]; j++)
            if (buffer[i] == s_c[j])
                return (remove_space(rmv_end_char(str)));
    }
    return (remove_space(str));
}

void end_separator(struct my_sh *s_sh, struct sep *sep_init,
    char *cmd_actu, char *last_cmd)
{
    cmd_actu = remove_space(cmd_actu);
    s_sh->sep->cmd = cmd_actu, s_sh->sep->last_cmd = last_cmd;
    s_sh->sep->next_cmd = NULL;
    s_sh->sep->type = 42;
    s_sh->sep->next = NULL;
    s_sh->sep = sep_init;
    execute_all(s_sh);
}

void fill_separator(char *buffer, struct my_sh *s_sh)
{
    char *cmd_actu = NULL;
    char *last_cmd = NULL;
    char s_c[] = {'|', '>', '<', ';', '&'};
    struct sep *sep_init = s_sh->sep;

    for (int j = 0; buffer[j]; j++) {
        cmd_actu = add_in_str(cmd_actu, buffer[j]);
        for (int i = 0; s_c[i]; i++)
            if (buffer[j] == s_c[i] && buffer[j + 1]) {
                cmd_actu = remove_space(rmv_end_char(cmd_actu));
                s_sh->sep->cmd = cmd_actu, s_sh->sep->last_cmd = last_cmd;
                s_sh->sep->next_cmd = get_next_cmd(buffer, s_c, j);
                s_sh->sep->next = malloc(sizeof(struct sep));
                s_sh->sep->type = gt(buffer, j), s_sh->sep = s_sh->sep->next;
                last_cmd = cmd_actu, cmd_actu = NULL;
                (gt(buffer, j) == 3 || gt(buffer, j) == 5) ? (j++) : (1);
            }
    }
    end_separator(s_sh, sep_init, remove_space(cmd_actu), last_cmd);
}