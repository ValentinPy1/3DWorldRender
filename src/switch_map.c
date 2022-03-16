/*
** EPITECH PROJECT, 2021
** world
** File description:
** switch_map.c
*/

#include "my_world.h"

void update_map(winbase_t *wb, double **height_map, float prop)
{
    int y;
    int x;
    for (y = 0; y < wb->world.dim.y; y++) {
        for (x = 0; x < wb->world.dim.x; x++) {
            wb->height_map[y][x] = wb->height_map[y][x] *\
            prop + height_map[y][x] * (1 - prop);
        }
    }
}

void update_colors(winbase_t *wb, w_colors_t colors, float prop)
{
    wb->world.colors.high.r = wb->world.colors.high.r *\
    0.95 + colors.high.r * 0.05;
    wb->world.colors.high.g = wb->world.colors.high.g *\
    0.95 + colors.high.g * 0.05;
    wb->world.colors.high.b = wb->world.colors.high.b *\
    0.95 + colors.high.b * 0.05;
    wb->world.colors.low.r = wb->world.colors.low.r *\
    0.95 + colors.low.r * 0.05;
    wb->world.colors.low.g = wb->world.colors.low.g *\
    0.95 + colors.low.g * 0.05;
    wb->world.colors.low.b = wb->world.colors.low.b *\
    0.95 + colors.low.b * 0.05;

}

void switch_map(winbase_t *wb)
{
    int i;
    sfVector2f **projmap;
    double **newmap = setup_map(wb->world.dim.x, wb->world.dim.y);;
    w_colors_t colors = setup_color();
    float prop = pow(0.95, (60.0 / (float)WINFPS));
    printf("prop: %f\n", prop);
    for (i = 0; i < 43 * WINFPS / 60.0; i++) {
        update_map(wb, newmap, prop);
        update_colors(wb, colors, prop);
        projmap = project_map(wb);
        draw_all(wb, projmap);
        destroy_projmap(&wb->world.dim, projmap);
    }
    for (i = 0; newmap[i] != NULL; i++)
        free(newmap[i]);
    free(newmap);
}

double **setup_blankmap(int width, int height)
{
    double **map = malloc((height + 1) * sizeof(double *));
    int y;
    int x;
    for (y = 0; y < height; y++) {
        map[y] = malloc(width * sizeof(double));
        for (x = 0; x < width; x++) {
            map[y][x] = 0;
        }
    }
    map[y] = NULL;
    return map;
}

void switch_blank(winbase_t *wb)
{
    int i;
    sfVector2f **projmap;
    double **newmap = setup_blankmap(wb->world.dim.x, wb->world.dim.y);
    float prop = pow(0.95, 60.0 / WINFPS);
    for (i = 0; i < 3 * WINFPS / 60; i++) {
        update_map(wb, newmap, prop);
        projmap = project_map(wb);
        draw_all(wb, projmap);
        destroy_projmap(&wb->world.dim, projmap);
    }
    for (i = 0; newmap[i] != NULL; i++)
        free(newmap[i]);
    free(newmap);
}