/*
** EPITECH PROJECT, 2021
** my_tower
** File description:
** csfmlprocess.c
*/

#include "my_world.h"

sfRenderWindow *create_window(void)
{
    sfVideoMode mode = {WINWIDTH, WINHEIGHT, WINBPP};
    const char *title = "my_world";
    return sfRenderWindow_create(mode, title,\
    sfClose | sfResize | sfFullscreen, NULL);
}

void handle_event(winbase_t *wb)
{
    while (sfRenderWindow_pollEvent(wb->window, &wb->event)) {
        switch (wb->event.type) {
            case (sfEvtClosed):
                sfRenderWindow_close(wb->window);
                break;
            case (sfEvtKeyPressed):
                kbd_input(wb);
                break;
            case (sfEvtMouseButtonPressed):
                test_buttons(wb);
                break;
            case (sfEvtMouseWheelMoved):
                wb->world.size *= pow(1.15, (float)wb->event.mouseWheel.delta);
                break;
            default:
                break;
        }
    }
}

winbase_t *create_winbase(void)
{
    winbase_t *wb = malloc(sizeof(winbase_t));
    srand(time(NULL));
    wb->window = create_window();
    wb->world = setup_world();
    wb->height_map = setup_map(wb->world.dim.x, wb->world.dim.y);
    sfRenderWindow_setFramerateLimit(wb->window, WINFPS);
    wb->menu.draw = 1;
    setup_buttons(wb);
    wb->font = sfFont_createFromFile("assets/font.otf");
    return wb;
}

void destroy_winbase(winbase_t *wb)
{
    int i;
    sfRenderWindow_destroy(wb->window);
    for (i = 0; wb->height_map[i] != NULL; i++)
        free(wb->height_map[i]);
    free(wb->height_map);
    sfMusic_destroy(wb->music);
    sfFont_destroy(wb->font);
    free(wb);
}

void draw_all(winbase_t *wb, sfVector2f **map, char *str)
{
    draw_x_lines(wb, map);
    draw_y_lines(wb, map);
    if (wb->menu.draw == 1) {
        sfRenderWindow_drawSprite(wb->window, wb->menu.flatten.sprite, NULL);
        sfRenderWindow_drawSprite(wb->window, wb->menu.redim.sprite, NULL);
        sfRenderWindow_drawSprite(wb->window, wb->menu.auto_rota.sprite, NULL);
    }
    display_str(wb, str);
    sfRenderWindow_display(wb->window);
    sfRenderWindow_clear(wb->window, sfBlack);
}
