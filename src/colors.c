/*
** EPITECH PROJECT, 2021
** world
** File description:
** colors.c
*/

#include "my_world.h"

sfColor build_color(w_colors_t colors, double vh)
{
    double max = colors.max;
    sfUint8 red = colors.low.r * (vh / max) + colors.high.r * (1 - vh / max);
    sfUint8 green = colors.low.g * (vh / max) + colors.high.g * (1 - vh / max);
    sfUint8 blue = colors.low.b * (vh / max) + colors.high.b * (1 - vh / max);
    return sfColor_fromRGB(red, green, blue);
}