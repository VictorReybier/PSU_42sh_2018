/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** All structures for 42sh
*/

struct sep {
    int type;
    char *last_cmd;
    char *cmd;
    char *next_cmd;
    char *path_last;
    char *path_cmd;
    struct sep *next;
};

struct my_sh {
    int return_val;
    char **env;
    char ***alias;
    char *oldpwd;
    struct sep *sep;
};
