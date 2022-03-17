/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** mouse_input.c
*/

#include "my_world.h"

int close_d(int num1, float num2, int distance)
{
    if (num1 + distance >= num2 && num1 - distance <= num2)
        return 1;
    return 0;
}

void adjust_points(winbase_t *wb, sfVector2i mouse_pos)
{
    int dist = 10;
    int y = wb->coord.y;
    int x = wb->coord.x;
    sfVector2f scaledpoint;

    if (close_d(mouse_pos.y, y, dist) == 1 && close_d(mouse_pos.x,
x, dist) == 1) {
        wb->height_map[y][x] += 1;
    }
}

sfVector2i scale_mouse(winbase_t *wb, sfVector2i mouse_pos, int factor)
{
    sfVector2i scaledpoint;

    scaledpoint.x = mouse_pos.x / factor;
    scaledpoint.y = mouse_pos.y / factor;

    return scaledpoint;
}

void check_points(winbase_t *wb, sfVector2i mouse_pos, sfVector2f **projmap,
int factor)
{
    int height = wb->world.dim.y;
    int width = wb->world.dim.x;

    mouse_pos = scale_mouse(wb, mouse_pos, factor);
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            wb->coord.y = y;
            wb->coord.x = x;
            adjust_points(wb, mouse_pos);
        }
    }
}

void handle_mouse(winbase_t *wb, sfVector2f **projmap, int factor)
{
    sfVector2i mouse_pos;
    sfBool right_button;
    sfBool left_button;

    mouse_pos = sfMouse_getPositionRenderWindow(wb->window);
    left_button = sfMouse_isButtonPressed(sfMouseLeft);
    if (left_button == sfTrue)
        check_points(wb, mouse_pos, projmap, factor);
}
