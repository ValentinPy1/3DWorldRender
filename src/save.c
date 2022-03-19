/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myworld-valentin.py
** File description:
** save.c
*/

#include "my_world.h"
#include "my.h"
#include<stdio.h>

void write_file(winbase_t *wb, FILE *fp, int y, int x)
{
    char *value;
}

void save(winbase_t *wb, const char *filepath)
{
    int fd;
    char *buffer;

    fd = open(filepath, O_CREAT | O_RDWR, 0777);
    buffer = my_getstr(wb->world.dim.y);
    write(fd, buffer, 3);
    for (int y = 0; y < wb->world.dim.y; ++y) {
        for (int x = 0; x < wb->world.dim.x; x++) {
        }
    }
    close(fd);
    return;
}