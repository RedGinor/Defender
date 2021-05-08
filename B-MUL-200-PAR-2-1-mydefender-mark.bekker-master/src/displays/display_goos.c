/*
** EPITECH PROJECT, 2021
** display_goos
** File description:
** displays enemys
*/

#include <defender.h>
#include <stdlib.h>

void move_on_path(sfRenderWindow *window, sprite_s *goo)
{
    if (goo->pos.x < 220) {
        move_sprite(goo, 'r', goo->speed);
        display_sprite(goo, window, false);
    } else if (goo->pos.y > -500) {
        move_sprite(goo, 'u', goo->speed);
        display_sprite(goo, window, false);
    }
}

void disp_goo(sfRenderWindow *window, goo_s *goos)
{
    for (int i = 7; i < 16; i++)
        if (goos->sprite[i]->is_displayed)
            move_on_path(window, goos->sprite[i]);
}

void set_display_goo(int *eve, goo_s *goos)
{
    int random = rand() % 3;

    if (eve[8] + eve[9] + eve[10] == 0)
        return;
    while (eve[8 + random] == 0)
        random = rand() % 3;
    eve[8 + random]--;
    for (int i = 0; i < 3; i++)
        for (int j = eve[8 + i]; j < 3; j++)
            goos->sprite[7 + i * 3 + j]->is_displayed = true;
}