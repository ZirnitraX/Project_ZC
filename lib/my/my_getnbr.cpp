/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** get a nbr at the begining if a string
*/

int my_getnbr(char *str)
{
    long long nb = 0;
    int i = 0;
    int neg_pos = -1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg_pos = -neg_pos;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (nb < (-2147483648 + (str[i] - '0')) / 10)
            return (0);
        int a = str[i] - '0';
        nb = (nb * 10) - a;
        i++;
    }
    if (neg_pos == -1 && nb == -2147483648)
        return (0);
    nb = nb * neg_pos;
    return (nb);
}
