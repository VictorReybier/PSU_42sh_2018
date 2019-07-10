/*
** EPITECH PROJECT, 2019
** str_to_word_array.c
** File description:
** convert char to double char
*/

#include "my.h"

int my_arraylen(char **array)
{
    int my_len = 0;

    for (; array[my_len]; my_len++);
    return (my_len);
}

char **push_array(char **array, char *str)
{
    char **new_array = malloc(sizeof(char *) * (my_arraylen(array) + 2));
    int i = 0;

    if (str == NULL)
        return (array);
    for (; array[i]; ++i)
        new_array[i] = array[i];
    new_array[i] = str;
    new_array[++i] = 0;
    return (new_array);
}

char **word_array(char *str, char separator)
{
    char **my_malloc = NULL;
    int size = 1;
    int j = 0;

    if (str == NULL)
        return (NULL);
    for (int i = 0; str[i]; ++i)
        size = size + (str[i] == separator);
    my_malloc = malloc(sizeof(char *) * (size + 1));
    my_malloc[j] = add_in_str(NULL, str[0]);
    for (int i = 1; str[i]; i++) {
        if (str[i] == separator && str[i + 1] != 0)
            my_malloc[++j] = add_in_str(NULL, str[++i]);
        else
            my_malloc[j] = add_in_str(my_malloc[j], str[i]);
    }
    my_malloc[++j] = NULL;

    return (my_malloc);
}
