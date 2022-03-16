/*
** EPITECH PROJECT, 2021
** world
** File description:
** handlebutton.c
*/

#include "my_world.h"

bool is_clicked(winbase_t *wb, button_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wb->window);
    int minx = button->pos.x;
    int miny = button->pos.y;
    int maxx = button->pos.x + button->size.x;
    int maxy = button->pos.y + button->size.y;
    if (mouse_pos.x > minx && mouse_pos.x < maxx &&\
    mouse_pos.y > miny && mouse_pos.y < maxy)
        return true;
    return false;
}