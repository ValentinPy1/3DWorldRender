/*
** EPITECH PROJECT, 2021
** world
** File description:
** switch_map.c
*/

#include "my_world.h"

void update_map(winbase_t *wb, double **height_map)
{
    int y;
    int x;
    for (y = 0; y < wb->world.dim.y; y++) {
        for (x = 0; x < wb->world.dim.x; x++) {
            wb->height_map[y][x] = wb->height_map[y][x] * 0.95 + height_map[y][x] * 0.05;
        }
    }
}
void switch_map(winbase_t *wb, double **height_map)
{
    int i;
    sfVector2f **projmap;
    for (i = 0; i < 50; i++) {
        update_map(wb, height_map);
        projmap = project_map(wb);
        draw_all(wb, projmap);
        destroy_projmap(&wb->world.dim, projmap);
    }
}