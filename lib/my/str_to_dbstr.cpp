/*
** EPITECH PROJECT, 2021
** str_to_dbstr
** File description:
** turn a string into a double string following '\n'
*/

#include "../../include/my.h"
#include <cstdlib>

int nb_line(char *buffer)
{
    int nb = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            nb++;
    return (nb + 1);
}

int file_len(char *str, int i, char to_compare)
{
    int k = 0;

    for (; str[i] != '\0' && str[i] != to_compare; i++, k++);
    return (k + 1);
}

char **str_to_dbstr(char *file, char end_line)
{
    char **map = NULL;
    int size = nb_line(file);

    map = (char**) malloc(sizeof(char *) * (size + 1));
    map[size] = NULL;
    for (int j = 0, i = 0, len_file = 0; j != size; j++) {
        len_file = file_len(file, i, end_line);
        i += len_file;
        map[j] = (char*) malloc(sizeof(char) * (len_file));
    }
    for (int i = 0, j = 0, k = 0; map[i] != NULL; i++, j++) {
        for (int k = 0; file[j] != end_line && file[j] != '\0'; j++, k++) {
            map[i][k] = file[j];
            map[i][k + 1] = '\0';
        }
    }
    return (map);
}