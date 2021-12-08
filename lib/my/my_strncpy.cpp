/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** function that copies n characters from a string into another.
*/

char *my_strncpy(char *dest , char  const *src , int n)
{
    int i = 0;

    while (src[i] != src[n] || src[i] != '\0') {
        dest[i] = src[i];
        i++;
        }
    if ( n > i)
        dest[i] = '\0';
    return (dest);
}
