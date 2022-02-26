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
    world.dim = (sfVector2f){6, 6};
    return world;
}

int **setup_map(int width, int height)
{
    int **map = malloc(width * sizeof(int *));
    int y;
    int x;

    for (y = 0; y < height; y++) {
        map[y] = malloc(width * sizeof(int));
        for (x = 0; x < width; x++) {
            map[y][x] = 0;
        }
    }
    return map;
}