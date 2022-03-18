/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** editor.c
*/

#include "my_world.h"

sfVector2f scale_editor(int y, int x, int factor)
{
    sfVector2f scaledpoint;
    scaledpoint.y = y * factor;
    scaledpoint.x = x * factor;
    return scaledpoint;
}

void editor_x_lines(winbase_t *wb, int factor)
{
    sfVertexArray *vertex_array;
    sfVertex vertex;
    sfVector2f scaledpoint;
    int x;
    int y;
    sfColor color;
    double vh;
    for (y = 0; y < wb->world.dim.y; y++) {
        vertex_array = sfVertexArray_create();
        for (x = 0; x < wb->world.dim.x; x++) {
            scaledpoint = scale_editor(y, x, factor);
            vh = wb->height_map[y][x] * 10;
            color = build_color(wb->world.colors, vh);
            vertex = (sfVertex){.position = scaledpoint, .color = color};
            sfVertexArray_append(vertex_array, vertex);
        }
        sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
        sfRenderWindow_drawVertexArray(wb->window, vertex_array, NULL);
        sfVertexArray_destroy(vertex_array);
    }
}

void editor_y_lines(winbase_t *wb, int factor)
{
    sfVertexArray *vertex_array;
    sfVertex vertex;
    sfVector2f scaledpoint;
    int x;
    int y;
    sfColor color;
    double vh;
    for (x = 0; x < wb->world.dim.x; x++) {
        vertex_array = sfVertexArray_create();
        for (y = 0; y < wb->world.dim.y; y++) {
            scaledpoint = scale_editor(y, x, factor);
            vh = wb->height_map[y][x] * 10;
            color = build_color(wb->world.colors, vh);
            vertex = (sfVertex){.position = scaledpoint, .color = color};
            sfVertexArray_append(vertex_array, vertex);
        }
        sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
        sfRenderWindow_drawVertexArray(wb->window, vertex_array, NULL);
        sfVertexArray_destroy(vertex_array);
    }
}

void editor(winbase_t *wb)
{
    int factor = 4;
    editor_x_lines(wb, factor);
    editor_y_lines(wb, factor);
    handle_mouse(wb, factor);
}