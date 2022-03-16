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

void adjust_points(winbase_t *wb, sfVector2f scaledpoint, sfVector2i mouse_pos,
int button)
{
    int dist = 10;
    int y = wb->coord.y;
    int x = wb->coord.x;

    if (close_d(mouse_pos.y, scaledpoint.y, dist) == 1 && close_d(mouse_pos.x,
    scaledpoint.x, dist) == 1) {
        wb->height_map[y][x] += button;
    }
}

void check_points(winbase_t *wb, sfVector2i mouse_pos, sfVector2f **projmap,
int button)
{
    int height = wb->world.dim.y;
    int width = wb->world.dim.x;
    sfVector2f scaledpoint;

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            scaledpoint = scale_point(wb, projmap, y, x);
            wb->coord.y = y;
            wb->coord.x = x;
            adjust_points(wb, scaledpoint, mouse_pos, button);
        }
    }
}

void wheelinput(winbase_t *wb)
{
    wb->world.size += wb->event.mouseWheel.delta;
}

void handle_mouse(winbase_t *wb, sfVector2f **projmap)
{
    sfVector2i mouse_pos;
    sfBool right_button;
    sfBool left_button;

    mouse_pos = sfMouse_getPositionRenderWindow(wb->window);
    left_button = sfMouse_isButtonPressed(sfMouseLeft);
    right_button = sfMouse_isButtonPressed(sfMouseRight);
    if (left_button == sfTrue)
        check_points(wb, mouse_pos, projmap, 1);
    if (right_button == sfTrue)
        check_points(wb, mouse_pos, projmap, -1);
}
