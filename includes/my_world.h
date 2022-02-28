/*
** EPITECH PROJECT, 2021
** common
** File description:
** common.h
*/

#ifndef _MY_RADAR_
    #define _MY_RADAR_
    #include <SFML/Graphics.h>
    #include <time.h>
    #include <SFML/Window/Mouse.h>
    #include <math.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "my.h"

    #define WINWIDTH 1920
    #define WINHEIGHT 1080
    #define WINFPS 60
    #define WINBPP 32
    #define PI 3.14159265359

typedef struct world_s {
    sfVector2i dim;
    sfVector2f pos;
    sfVector2f angle;
    float size;
} world_t;

typedef struct winbase_s {
    sfRenderWindow *window;
    sfEvent event;
    int **height_map;
    world_t world;
} winbase_t;
sfVector2f scale_point(winbase_t *wb, sfVector2f **map, int y, int x);
winbase_t *create_winbase(void);
void handle_event(winbase_t *);
sfRenderWindow *create_window(void);
void destroy_winbase(winbase_t *);
void draw_all(winbase_t *, sfVector2f **);
int **setup_map(int, int);
void draw_x_lines(winbase_t *, sfVector2f **);
void draw_y_lines(winbase_t *, sfVector2f **);
sfVector2f **project_map(winbase_t *);
world_t setup_world(void);
void kbd_input(winbase_t *);
void destroy_projmap(sfVector2f *, sfVector2f **);

#endif
