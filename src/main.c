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
    sfVector2f **projmap = project_map(wb);
    while (sfRenderWindow_isOpen(wb->window)) {
        draw_all(wb, projmap);
        handle_event(wb);
    }
    destroy_winbase(wb);
}

void print_help()
{
    my_putstr("help\n");
}

int main(int ac, char **av)
{
    launch();
    return 0;
}
