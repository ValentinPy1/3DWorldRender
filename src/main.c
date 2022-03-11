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
        draw_all(wb, projmap);
        destroy_projmap(&wb->world.dim, projmap);
        handle_event(wb);
        handle_mouse(wb, projmap);
    }
    destroy_winbase(wb);
}

void print_help()
{
    my_putstr("help\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h"))
        printf("usage\n");
    launch();
    return 0;
}
