/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** mouse_input.c
*/

#include "my_world.h"

void check_points(winbase_t *wb, sfVector2i mouse_pos, sfVector2f **projmap, 
int button)
{
    int lines = wb->world.dim.y;
    int cols = wb->world.dim.x;
    sfVector2i point_pos;
    sfVector2f scaledpoint;

    for (int i = 0; i <= lines; i++) {
        for (int j = 0; j <= cols; j++) {
            scale_point(wb, wb->height_map, i, j);
            wb->coord.y = i;
            wb->coord.x = j;
            //adjust_points(wb, scaledpoint, mouse_pos);
        }
    }
}

void handle_mouse(winbase_t *wb, sfVector2f **projmap)
{
    sfVector2i mouse_pos;
    sfBool right_button, left_button;
    
    mouse_pos = sfMouse_getPositionRenderWindow(wb->window);
    left_button = sfMouse_isButtonPressed(sfMouseLeft);
    right_button = sfMouse_isButtonPressed(sfMouseRight);
    if (left_button == sfTrue)
        check_points(wb, mouse_pos, projmap, 1);
    return;
}