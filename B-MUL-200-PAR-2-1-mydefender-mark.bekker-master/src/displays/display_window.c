/*
** EPITECH PROJECT, 2021
** display_window
** File description:
** displays window
*/

#include <defender.h>
#include <stdlib.h>

void display_window(sfRenderWindow *window, sound_s *music, goo_s *goos)
{
    sfEvent event;
    int *eve = malloc(sizeof(int) * 15);

    reset_eve(eve);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            check_event(event, window, eve, goos);
        sfRenderWindow_clear(window, sfBlack);
        play_sfx(event, music);
        if (eve[2]) {
            disp_game(window, eve, goos);
            play_game(window, eve, goos);
        } else
            disp_menu(window, eve, goos);
        play_music(music, eve);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    free(eve);
}