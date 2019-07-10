/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** Display the number as parameter
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < -2147483648)
        my_putstr("-2147483648");
    else{
        int pw = 1;
        if (nb < 0) {
            my_putchar('-');
            nb = -nb;
        }
        int nb2 = nb;
        while (nb2 > 9) {
            pw = pw * 10;
            nb2 = nb2 / 10;
        }
        while (nb > 9) {
            my_putchar((nb / pw) + 48);
            nb = nb % pw;
            pw = pw / 10;
        }
        my_putchar(nb + 48);
    }
}