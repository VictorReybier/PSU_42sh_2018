/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Function to display in terminal
*/

#include <stdarg.h>
#include "my.h"

int dec_to_base(int n, int base, int maj)
{
    int i;
    int count;
    int nb2 = n;
    int result;

    for (count = 0; nb2 > 0; count++)
        nb2 = nb2 / base;
    int reste[count];
    for (i = 0 ; n > 0 ; i++) {
        result = n % base;
        if (result >= 10)
            (maj == 0) ? (result = result + 39) : (result = result + 7);
        reste[i] = result;
        n = n / base;
    }
    if (base == 8)
        for (int j = i; j < 3; j++)
            my_putstr("0");
    for (int k = i - 1 ; k >= 0; k--)
        my_putchar(reste[k] + 48);
}

void second_print(int my_int, va_list valist)
{
    switch (my_int) {
    case 'b' :
    case 'o' :
        dec_to_base(va_arg(valist, int), (my_int == 'b') ? 2 : 8, 0);
        break;
    case 'x' :
    case 'X' :
        dec_to_base(va_arg(valist, int), 16, (my_int == 'x') ? 0 : 1);
        break;
    case 'u' :
        dec_to_base(va_arg(valist, int), 10, 0);
        break;
    case 'p' :
        break;
    default :
        my_putchar('%');
        my_putchar(my_int);
    }
}

void first_print(int my_int, va_list valist)
{
    switch (my_int) {
    case 'c' :
        my_putchar(va_arg(valist, int));
        break;
    case 'S' :
    case 's' :
        my_putstr(va_arg(valist, char *));
        break;
    case 'd' :
    case 'i' :
        my_put_nbr(va_arg(valist, int));
        break;
    case '%':
        my_putchar('%');
        break;
    default :
        second_print(my_int, valist);
    }
}

void test_signe(int nb)
{
    if (nb > 0)
        my_putchar('+');
    my_put_nbr(nb);
}

void my_printf(char *str, ...)
{
    va_list valist;

    va_start(valist, str);
    for (int i = 0; str[i]; i++)
        if (str[i] == '%') {
            i++;
            if (str[i] == '+'){
                test_signe(va_arg(valist, int));
                i++;
            } else
                first_print(str[i], valist);
        } else
            my_putchar(str[i]);
    va_end(valist);
}
