/*
** EPITECH PROJECT, 2021
** my_world_bs
** File description:
** setup_map.c
*/

#include "my_world.h"

w_colors_t setup_color(void)
{
    w_colors_t colors;
    colors.high = sfColor_fromRGB(rdm() * 255, rdm() * 255, rdm() * 255);
    colors.low = sfColor_fromRGB(rdm() * 255, rdm() * 255, rdm() * 255);
    colors.max = 255;
    return colors;
}

sin_t *setup_sinlist(int n)
{
    sin_t *sin = malloc((n + 1) * sizeof(sin_t));
    int i;
    float off;
    float peak = 8;
    float period = 16;
    for (i = 0; i < n; i++) {
        off = rdm() * 100;
        sin[i] = (sin_t){off, peak, period};
        peak /= 0.5 + 3 * rdm();
        period /= 0.5 + 3 * rdm();
    }
    sin[i] = (sin_t){0, 0, 0};
    return sin;
}

world_t setup_world(void)
{
    world_t world;
    world.pos = (sfVector2f){WINWIDTH / 2, WINHEIGHT / 2};
    world.angle = (sfVector2f){15, 15};
    world.size = 1000;
    world.dim = (sfVector2i){100, 100};
    world.colors = setup_color();
    return world;
}

double **setup_map(int width, int height)
{
    double **map = malloc((height + 1) * sizeof(double *));
    int y;
    int x;
    sin_t *x_sin = setup_sinlist(4);
    sin_t *y_sin = setup_sinlist(4);
    for (y = 0; y < height; y++) {
        map[y] = malloc(width * sizeof(double));
        for (x = 0; x < width; x++) {
            map[y][x] = calc_sinlist(x_sin, y_sin, x, y);
        }
    }
    map[y] = NULL;
    return map;
}
