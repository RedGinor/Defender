/*
** EPITECH PROJECT, 2021
** display_life
** File description:
** displays lifes
*/

#include <defender.h>

void disp_lives(sfRenderWindow *window, int *eve, goo_s *goos)
{
    if (!eve[1]) {
        for (int i = 0; i < eve[11]; i++)
            display_sprite(goos->sprite[4 + i], window, false);
        for (int i = eve[11]; i < 3; i++)
            display_sprite(goos->sprite[i + 1], window, false);
    }
    for (int i = 7; i < 16; i++) {
        if (goos->sprite[i]->pos.y <= -500) {
            eve[11]--;
            sfSprite_setPosition(goos->sprite[i]->sprite, (sfVector2f){0, 0});
            goos->sprite[i]->pos = (sfVector2f){0, 0};
            goos->sprite[i]->is_displayed = false;
            eve[8 + (i - 7) / 3]++;
        }
    }
    if (eve[11] == 0) {
        eve[13] = true;
        eve[2] = false;
    }
}