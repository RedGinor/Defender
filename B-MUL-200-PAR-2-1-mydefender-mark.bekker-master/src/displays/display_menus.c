/*
** EPITECH PROJECT, 2021
** display_menus
** File description:
** displays all the menus
*/

#include <defender.h>

void disp_sett(sfRenderWindow *window, int *eve, goo_s *goos)
{
    display_sprite(goos->sprite[20], window, false);
    display_sprite(goos->sprite[16 + eve[4]], window, false);
    display_sprite(goos->sprite[18 + eve[5]], window, false);
    display_sprite(goos->sprite[21 + eve[12]], window, false);
}

void disp_game(sfRenderWindow *window, int *eve, goo_s *goos)
{
    if (eve[0])
        eve[6] = false;
    display_sprite(goos->sprite[23], window, false);
    if (eve[6])
        display_sprite(goos->sprite[25], window, false);
    if (eve[1] && !eve[6]) {
        display_sprite(goos->sprite[24], window, false);
        if (eve[3])
            disp_sett(window, eve, goos);
    }
}

void disp_menu(sfRenderWindow *window, int *eve, goo_s *goos)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = {tmp.x - 800, tmp.y - 600};

    if (pos.x > 0 || pos.x < -800 || pos.y > 0 || pos.y < -600)
        pos = (sfVector2f){-400, -300};
    goos->sprite[27]->pos = pos;
    display_sprite(goos->sprite[26], window, false);
    display_sprite(goos->sprite[27], window, false);
    if (eve[3])
        disp_sett(window, eve, goos);
    if (eve[13])
        disp_lose(window, goos);
}