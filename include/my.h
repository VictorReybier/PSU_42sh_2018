/*
** EPITECH PROJECT, 2019
** Project Name
** File description:
** All prototypes of functions
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "struct.h"

#define IS_NUM(c) (c >= '0' && c <= '9')
#define IS_BAD_START(c) (c != -62 && c != -61 && c < 'A' ||\
 c > 'Z' && c < 'a' || c > 'z')
#define IS_NO_ALPHA(c) (c != -62 && c != -61 && c < '0' || \
c > '9' && c < 'A' || c > 'Z' && c < 'a' || c > 'z')
#define PATH_ENV "/usr/local/sbin:/usr/local/bin:/usr/sbin:\
/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"
#define ERROR_FORMAT ": Exec format error. Wrong Architecture."

// Prototypes of Library
char *add_in_str(char *str, char c);
char *remove_space(char *str);
char *rmv_entry(char *str);
int same_start(char *str1, char *str2);
char **word_array(char *str, char separator);
char *my_strcat(char *str1, char *str2);
int my_arraylen(char **array);
char **push_array(char **array, char *str);
char *my_realloc(char *str, int size);
char *srch_env(char **env, char *search);
void my_printf(char *str, ...);
void my_putchar(char c);
int my_putstr(char *str);
int my_put_nbr(int nb);

// Prototypes of Sh Library
char *get_path(char *str);
char *get_env(char **env, char *search);
char *rmv_end_char(char *str);
int find_char(char *str, char c);
char *rmv_par(char *str);

// Prototypes of others functions
void exec_cmd(struct my_sh *s_sh, char *exec);
void exec_file(char *cmd, struct my_sh *s_sh);
void display_env(char **env);
int manage_exit(char *cmd);
char *find_files(char *path, char *exec);
void create_new_env(char **rl_cmd, struct my_sh *s_sh);
void rewrite_env(char **rl_cmd, int i, struct my_sh *s_sh);
void do_env(char **rl_cmd, char *cmd, struct my_sh *s_sh);
int error_setenv(char **rl_cmd);
void my_setenv(char *cmd, struct my_sh *s_sh);
void remove_env(char **rl_cmd, int nb, int i, struct my_sh *s_sh);
void my_unsetenv(char *cmd, struct my_sh *s_sh);
int str_hard_cmp(char const *s1, char const *s2);
int cnt_space(char *str);
int is_alphanumeric(char *str);
char ***dd_str(char ***str, char **d_str);
int my_exec(struct my_sh *s_sh);
char *get_path_file_exec(char *cmd);
int change_dir(char **array, struct my_sh *s_sh);
void fill_separator(char *buffer, struct my_sh *s_sh);
int manage_cmd(char *cmd, struct my_sh *s_sh, int nb);
int my_echo(char *line, struct my_sh *sh);
void manage_alias(char *line, struct my_sh *s_sh);
char *check_alias(char *line, struct my_sh *s_sh);
void mdf_pwd(char **env, char **array, int save);
void create_env(struct my_sh *s_sh);
int write_in_file(struct my_sh *s_sh, char *ne, char *nf, int write_end);
void exec_pipe(char ***cmd, struct my_sh *s_sh);
void manage_pipe(struct my_sh *s_sh);
void simple_exec(struct my_sh *s_sh);

#endif
