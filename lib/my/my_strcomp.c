/*
** EPITECH PROJECT, 2019
** my_strcomp.c
** File description:
** Compare two strings
*/

int same_start(char *str1, char *str2)
{
    for (int i = 0; str2[i]; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

int str_hard_cmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}