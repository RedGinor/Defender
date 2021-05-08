/*
** EPITECH PROJECT, 2021
** main
** File description:
** main functions
*/

#include <defender.h>
#include <unistd.h>
#include <stdlib.h>

int rule(char **av)
{
    if (av[1][0]  == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        write(1, "Goo - Infinite rush\n", 20);
        write(1, "The objective is to defend an area against successive", 53);
        write(1, " waves of enemies moving along a route or not, buildin", 54);
        write(1, "g and progressively advancing defensive towers\n", 47);
        write(1, "GOOD LUCK\n", 10);
    }
    else
        write(1, "Wrong Flags", 11);
    return 0;
}

int main(int ac, char __attribute__((unused))**av)
{
    char *name = "Goo - Infinite rush";
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, name, sfClose, NULL);
    goo_s *goos = malloc(sizeof(goo_s));
    sound_s sound;

    initiate_sound(&sound);
    initiate_goos(goos);
    if (ac == 2) {
        rule(av);
        return (0);
    }
    if (error_handler(ac))
        return (84);
    display_window(window, &sound, goos);
    clear_sound(&sound);
    clear_goos(goos);
    return (0);
}