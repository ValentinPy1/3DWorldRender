/*
** EPITECH PROJECT, 2021
** get number
** File description:
** get int from a string
*/

#include "my.h"

int my_atoi(char const *str)
{
    int len = my_strlen(str);
    int i;
    int mult = 1;
    int number = 0;
    int offset;
    if (str[0] == '-')
        offset = 1;
    else
        offset = 0;
    for (i = len - 1; i >= offset; i--) {
        number += (str[i] - 48) * mult;
        mult *= 10;
    }
    return (-1 * number * (2 * offset - 1));
}
