/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** unction that reverses a string
*/

char *my_revstr(char *str)
{
    char swap;
    int max;

    while (str[max] != '\0') {
        max++;
    }
    for (int min = 0; max != min; min++) {
        max--;
        swap = str[max];
        str[max] = str[min];
        str[min] = swap;
    }
    return (str);
}
