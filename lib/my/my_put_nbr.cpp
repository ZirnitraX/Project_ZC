/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** Task07
*/

void my_putchar(char c);

void    my_put_nbr(int nb)
{
    long long n = nb;
    if ( n < 0) {
        my_putchar('-');
        n = -n;
    } if (n > 9) {
        my_put_nbr(n / 10);
    }
    my_putchar(n % 10 + '0');
}
