/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** load.c
*/

#include "my_world.h"
#include <stdio.h>

void splitter(const char *src, char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    while (src[i] != ' ') {
        str1[i] = src[i];
        i++;
    }
    str1[i++] = '\0';
    while (src[i] != '\n')
        str2[j++] = src[i++];
    str2[j] = '\0';
}

void get_dimensions(winbase_t *wb, const char *line)
{
    char *y = malloc(10);
    char *x = malloc(10);

    splitter(line, y, x);
    wb->world.dim.y = my_atoi(y);
    wb->world.dim.x = my_atoi(x);
}

void load_file(winbase_t *wb, const char *buffer, int y, int x)
{
    float value = my_atoi(buffer);
    int maxy = wb->world.dim.y;
    int maxx = wb->world.dim.x;

    if (y + 1 >= maxy && x + 1 >= maxx)
        return;
    value /= 10;
    wb->height_map[y][x] = value;
}

void load(winbase_t *wb, const char *filepath)
{
    FILE *fp;
    ssize_t line_size;
    char *buffer = NULL;
    size_t line_buf_size = 0;

    fp = fopen(filepath, "r");
    if (!fp)
        return;
    line_size = getline(&buffer, &line_buf_size, fp);
    get_dimensions(wb, buffer);

    for (int y = 0; y < wb->world.dim.y; y++) {
        for (int x = 0; x < wb->world.dim.x; x++) {
            line_size = getline(&buffer, &line_buf_size, fp);
            load_file(wb, buffer, y, x);
        }
    }
}