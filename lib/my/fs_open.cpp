/*
** EPITECH PROJECT, 2020
** fs_open
** File description:
** open e file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../../include/my.h"

int load_file_in_mem(char const *filepath)
{
    struct stat buff;

    stat(filepath, &buff);
    return (buff.st_size);
}

char const *fs_open_file(char const *filepath)
{
    int fd = 0;
    int size = 0;
    int sq_size = load_file_in_mem(filepath);
    char *buffer = (char*) malloc(sizeof(char) * (sq_size));

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr_error("fail tu open the file\n");
        return ("error");
    }
    size = read(fd, buffer, sq_size);
    if (size == -1)
        my_putstr_error("size error (open file)\n");
    close(fd);
    return (buffer);
}