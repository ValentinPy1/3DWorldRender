/*
** EPITECH PROJECT, 2021
** my_world_bs
** File description:
** setup_map.c
*/

#include "my_world.h"

double rdm(void)
{
    return (double)rand() / (double)RAND_MAX;
}

w_colors_t setup_color(void)
{
    w_colors_t colors;
    colors.high = sfColor_fromRGB(rdm() * 255, rdm() * 255, rdm() * 255);
    colors.low = sfColor_fromRGB(rdm() * 255, rdm() * 255, rdm() * 255);
    colors.max = 255;
    return colors;
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
    double sin1x_off = rdm() * 10;
    double sin2x_off = rdm() * 10;
    double sin3x_off = rdm() * 10;
    double sin1y_off = rdm() * 10;
    double sin2y_off = rdm() * 10;
    double sin3y_off = rdm() * 10;
    for (y = 0; y < height; y++) {
        map[y] = malloc(width * sizeof(double));
        for (x = 0; x < width; x++) {
            map[y][x] = sin(sin1x_off + (double)x / 16) * 8 + sin(sin2x_off + \
            (double)x / 8) * 4 + sin(sin3x_off + (double)x / 4) * 2 + \
            sin(sin1y_off + (double)y / 16) * 8 + sin(sin2y_off + (double)y / \
            8) * 4 + sin(sin3y_off + (double)y / 4) * 2 + \
            rdm() - rdm();
        }
    }
    map[y] = NULL;
    return map;
}

void destroy_projmap(sfVector2i *dim, sfVector2f **projmap)
{
    int i;
    for (i = 0; i < dim->y; i++)
        free(projmap[i]);
    free(projmap);
}