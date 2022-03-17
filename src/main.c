/*
** EPITECH PROJECT, 2021
** common
** File description:
** main
*/

#include "my_world.h"

void launch(void)
{
    winbase_t *wb = create_winbase();
    sfVector2f **projmap;
    play_music(wb);
    while (sfRenderWindow_isOpen(wb->window)) {
        projmap = project_map(wb);
        draw_all(wb, projmap, "");
        destroy_projmap(&wb->world.dim, projmap);
        handle_event(wb);
        wb->world.angle.x += wb->world.rota;
        //handle_mouse(wb, projmap);
    }
    destroy_winbase(wb);
}

void print_help()
{
    my_putstr("\nUSAGE:\n");
    my_putstr("    ARROWS    : move\n");
    my_putstr("    ZQSD      : change angle\n");
    my_putstr("    PM        : zoom and unzoom\n");
    my_putstr("    R         : regenerate a new map\n");
    my_putstr("    B         : generate blank map\n");
    my_putstr("    BACKSPACE : close window\n\n");
}

int main(int ac, char **av)
{
    if (ac >= 2 && my_strcmp(av[1], "-h")) {
        print_help();
    } else {
        launch();
    }
    return 0;
}
