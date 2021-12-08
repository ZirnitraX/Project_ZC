/*
** EPITECH PROJECT, 2020
** is_my_prime.c
** File description:
** Task06
*/

int my_is_prime(int nb)
{
    int b;

    if (nb == 0 || nb < 0 || nb == 1) {
        return 0;
    }
    for (b = 2; b < nb; b++) {
        if (nb % b == 0) {
            return 0;
        }
    }
    return 1;
}
