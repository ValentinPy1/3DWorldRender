/*
** EPITECH PROJECT, 2021
** world
** File description:
** handlebutton.c
*/

#include "my_world.h"

void test_buttons(winbase_t *wb)
{
    if (is_clicked(wb, &wb->menu.flatten)) {
        switch_blank(wb);
    } else if (is_clicked(wb, &wb->menu.redim)) {
        redim_trigger(wb);
    } else if (is_clicked(wb, &wb->menu.auto_rota)) {
        if (wb->event.mouseButton.button == sfMouseLeft)
            wb->world.rota += 0.2;
        if (wb->event.mouseButton.button == sfMouseRight)
            wb->world.rota -= 0.2;
    }
}

void setup_buttons(winbase_t *wb)
{
    wb->menu.flatten = setup_button((sfVector2f){1700, 50},\
    (sfVector2f){0.5, 0.5}, "assets/flattenmap.png");
    wb->menu.redim = setup_button((sfVector2f){1700, 100},\
    (sfVector2f){0.5, 0.5}, "assets/redimension.png");
    wb->menu.auto_rota = setup_button((sfVector2f){1700, 150},\
    (sfVector2f){0.5, 0.5}, "assets/autorota.png");
}

void display_str(winbase_t *wb, char *str)
{
    sfVector2f position = {100, 90};
    sfVector2f scale = {1.5, 1.5};
    sfText *text = sfText_create();
    sfText_setPosition(text, position);
    sfText_setString(text, str);
    sfText_setColor(text, sfWhite);
    sfText_setFont(text, wb->font);
    sfText_setScale(text, scale);
    sfRenderWindow_drawText(wb->window, text, NULL);
    sfText_destroy(text);
}

bool is_clicked(winbase_t *wb, button_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wb->window);
    int minx = button->pos.x;
    int miny = button->pos.y;
    int maxx = button->pos.x + button->size.x;
    int maxy = button->pos.y + button->size.y;
    if (mouse_pos.x > minx && mouse_pos.x < maxx && \
    mouse_pos.y > miny && mouse_pos.y < maxy)
        return true;
    return false;
}