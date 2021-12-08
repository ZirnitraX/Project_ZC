/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copies a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
