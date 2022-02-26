/*
** EPITECH PROJECT, 2021
** my_world_bs
** File description:
** mange_input.c
*/

#include "my_world.h"

void kbd_input(winbase_t *wb)
{
    switch (wb->event.key.code) {
        case (sfKeyD):
            wb->world.pos.x += 10;
            my_printf("ziz %i\n", wb->world.pos.x);
            break;
        case (sfKeyQ):
            wb->world.pos.x -= 1;
            break;
        case (sfKeyZ):
            wb->world.pos.y += 1;
            break;
        case (sfKeyS):
            wb->world.pos.y -= 1;
            break;
        default:
            break;
    }
}
