/*
** EPITECH PROJECT, 2021
** my_nbrlen
** File description:
** len of a number
*/

int my_nbrlen(int str)
{
    int c = 0;

    for (; str > 0; str /= 10) {
        c++;
    }
    return (c);
}