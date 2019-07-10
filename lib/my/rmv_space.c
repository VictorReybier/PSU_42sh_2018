/*
** EPITECH PROJECT, 2019
** rmv_space.c
** File description:
** remove space
*/

#include <my.h>

int count_space(char *str)
{
    int count = 0;
    int i = 0;
    int size = 0;

    while (str[i] && str[i] == ' ')
        i++;
    for (; str[i]; i++) {
        if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            count = 1;
        else
            count = 0;
        (count == 0) ? (size++) : (1);
    }
    return (size);
}

char *remove_space(char *str)
{
    char *new_str = malloc(sizeof(char) * 2);
    int i = 0;
    int len = 0;

    if (str == NULL)
        return (NULL);
    for (int j = 0; str[j]; j++)
        if (str[j] == 9)
            str[j] = ' ';
    while (str[i] && str[i] == ' ')
        i++;
    new_str[0] = str[i++], new_str[1] = '\0';
    for (; str[i]; i++)
        if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'));
        else
            new_str = add_in_str(new_str, str[i]);
    len = strlen(new_str);
    if (new_str[len - 1] == 32)
        new_str[len] = '\0';
    return (new_str);
}
