/*
** EPITECH PROJECT, 2020
** my_power
** File description:
** make the square of a number
*/

int my_power(int nb, int power)
{
    int nbr = nb;

    for (; power != 1; power--) {
        if (nb * nbr > 2147483647)
            return (0);
        nb = nb * nbr;
    }
    return (nb);
}
