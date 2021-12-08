/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** put a char or a string on the exit or error output
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
            my_putchar(str[i]);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putstr_error(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_error(str[i]);
}
