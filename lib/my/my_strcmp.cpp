/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** compare 2 string and tell who's bigger
*/

int my_strcmp(char const *s1, char const *s2)
{
    int nb_s1 = 0;
    int nb_s2 = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        nb_s1 += s1[i];
    for (int i = 0; s2[i] != '\0'; i++)
        nb_s2 += s2[i];
    if (nb_s1 == nb_s2)
        return (0);
    else if (nb_s1 < nb_s2)
        return (-1);
    else
        return (1);
}
