/*
** EPITECH PROJECT, 2021
** B-SYN-200-NCY-2-1-FASTAtools-bastien.star
** File description:
** tell if the str is a num (1 for yes 0 for no)
*/

int my_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > '9' || str[i] < '0' )
            return (0);
    return (1);
}