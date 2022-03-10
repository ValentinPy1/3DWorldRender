/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** mouse_input.c
*/

#include "my_world.h"


/*
void check_points(winbase_t *wb, sfVector2i mouse_pos, sfVector2f **projmap,
int close_d(int num1, float num2, int distance)
{
    if (num1 + distance > num2 && num1 - distance < num2)
        return 1;
    return 0;
}

void adjust_points(winbase_t *wb, sfVector2f scaledpoint, sfVector2i mouse_pos)
{
    int dist = 10;
    int y = wb->coord.y;
    int x = wb->coord.x;

    //printf("%.3f %.3f\n%d %d\n", scaledpoint.y, scaledpoint.x, y, x);
    if (close_d(mouse_pos.y, scaledpoint.y, dist) == 1 && close_d(mouse_pos.x,
    scaledpoint.x, dist) == 1) {
        wb->height_map[y][x] += 1;
    }
}

void check_points(winbase_t *wb, sfVector2i mouse_pos, sfVector2f **projmap,
>>>>>>> 0dea035b226eeea7a64ca3615bef357c14ed2716
int button)
{
    int lines = wb->world.dim.y;
    int cols = wb->world.dim.x;
    sfVector2i point_pos;
    sfVector2f scaledpoint;

    for (int i = 0; i <= lines; i++) {
        for (int j = 0; j <= cols; j++) {
            scaledpoint = scale_point(wb, wb->height_map, i, j);
            wb->coord.y = i;
            wb->coord.x = j;
            adjust_points(wb, scaledpoint, mouse_pos);
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
*/