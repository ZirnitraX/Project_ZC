/*
** EPITECH PROJECT, 2020
** my_compte_square_root.c
** File description:
** Task05
*/

int my_compute_square_root(int nb)
{
    int x = 0;
    int v = 0;

    while (x*x != nb)
    {
        if (x*x > nb || nb < 0)
        {
            return (0);
        }
        x++;
    }
    return (x);
}
