/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** compare n char in 2 string
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int nb_s1 = 0;
    int nb_s2 = 0;

    for (int i = 0; s1[i] != '\0' || i != n; i++)
        nb_s1 += s1[i];
    for (int i = 0; s2[i] != '\0' || i != n; i++)
        nb_s2 += s2[i];
    if (nb_s1 == nb_s2)
        return (0);
    else if (nb_s1 < nb_s2)
        return (-1);
    else
        return (1);
}
