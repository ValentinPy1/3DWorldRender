/*
** EPITECH PROJECT, 2021
** my_world_bs
** File description:
** mange_input.c
*/

#include "my_world.h"

void angle_input(winbase_t *wb)
{
    switch (wb->event.key.code) {
        case (sfKeyD):
            wb->world.angle.x += 2;
            break;
        case (sfKeyQ):
            wb->world.angle.x -= 2;
            break;
        case (sfKeyZ):
            wb->world.angle.y += 2;
            break;
        case (sfKeyS):
            wb->world.angle.y -= 2;
            break;
        default:
            break;
    }
}

void pos_input(winbase_t *wb)
{
    switch (wb->event.key.code) {
        case (sfKeyLeft):
            wb->world.pos.x -= 10;
            break;
        case (sfKeyRight):
            wb->world.pos.x += 10;
            break;
        case (sfKeyDown):
            wb->world.pos.y += 10;
            break;
        case (sfKeyUp):
            wb->world.pos.y -= 10;
            break;
        default:
            break;
    }
}

void size_input(winbase_t *wb)
{
    int i;
    double **newmap;
    switch (wb->event.key.code) {
        case (sfKeyP):
            wb->world.size *= 1.03;
            break;
        case (sfKeyM):
            wb->world.size /= 1.03;
            break;
        case (sfKeyR):
            wb->world.colors = setup_color();
            newmap = setup_map(wb->world.dim.x, wb->world.dim.y);
            switch_map(wb, newmap);
            for (i = 0; newmap[i] != NULL; i++)
                free(newmap[i]);
            free(newmap);
        default:
            break;
    }
}

void kbd_input(winbase_t *wb)
{
    angle_input(wb);
    pos_input(wb);
    size_input(wb);
}
