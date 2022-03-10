/*
** EPITECH PROJECT, 2021
** my_world_bs
** File description:
** setup_map.c
*/

#include "my_world.h"

world_t setup_world(void)
{
    world_t world;
    world.pos = (sfVector2f){WINWIDTH / 2, WINHEIGHT / 2};
    world.angle = (sfVector2f){15, 15};
    world.size = 400;
    world.dim = (sfVector2i){50, 50};
    return world;
}

double get_random(void)
{
    return (double)rand() / (double)RAND_MAX;
}

double **setup_map(int width, int height)
{
    double **map = malloc(width * sizeof(double *));
    int y;
    int x;
    double sin1x_off = get_random() * 10;
    double sin2x_off = get_random() * 10;
    double sin3x_off = get_random() * 10;
    double sin1y_off = get_random() * 10;
    double sin2y_off = get_random() * 10;
    double sin3y_off = get_random() * 10;

    for (y = 0; y < height; y++) {
        map[y] = malloc(width * sizeof(double));
        for (x = 0; x < width; x++) {
            map[y][x] = sin(sin1x_off + x / 8) * 4 + sin(sin2x_off + x / 4) *\
            2 + sin(sin3x_off + x / 2) * 1 + sin(sin1y_off + y / 8) * 4 +\
            sin(sin2y_off + y / 4) * 2 + sin(sin3y_off + y / 2) * 1 +\
            get_random();
        }
    }
    return map;
}

void destroy_projmap(sfVector2i *dim, sfVector2f **projmap)
{
    int i;
    for (i = 0; i < dim->y; i++)
        free(projmap[i]);
    free(projmap);
}