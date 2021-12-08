/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** puts every letter of every word in it in lowercase.
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    return (str);
}
