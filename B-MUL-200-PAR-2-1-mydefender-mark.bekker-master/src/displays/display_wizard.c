/*
** EPITECH PROJECT, 2021
** display_sorcier.c
** File description:
** 
*/

#include <defender.h>

void animation(sfIntRect *rect, goo_s *goos)
{
    static float tmp = 0;

    tmp += 0.1;
    if (tmp >= 1) {
        rect->left = rect->left + 132;
        tmp = 0;
    }
    if (rect->left == 528)
        rect->left = 0;
    sfSprite_setTextureRect(goos->sprite[29]->sprite, goos->sprite[29]->rect);
}

void get_focus(int i, goo_s *goos, sfVector2i tmp1, sfVector2i tmp2)
{
    if (goos->sprite[i]->is_displayed && is_ch(tmp1, tmp2, 120)) {
        animation(&goos->sprite[29]->rect, goos);
        if (!goos->sprite[29]->focus) {
            goos->sprite[i]->focus = true;
            goos->sprite[29]->focus = true;
        }
    } else if (goos->sprite[i]->focus) {
        goos->sprite[i]->focus = false;
        goos->sprite[29]->focus = false;
    }
    if (goos->sprite[i]->focus)
        goos->sprite[i]->life -= 1;
}

void disp_wizard(sfRenderWindow *window, int *eve, goo_s *goos)
{
    sfVector2i tmp1 = {0, 0};
    sfVector2i tmp2 = {goos->sprite[29]->pos.x - 100, goos->sprite[29]->pos.y - 440};

    display_sprite(goos->sprite[29], window, false);
    for (int i = 7; i < 16; i++) {
        if (goos->sprite[i]->is_displayed)
            tmp1 = (sfVector2i){goos->sprite[i]->pos.x, goos->sprite[i]->pos.y};
        get_focus(i, goos, tmp1, tmp2);
        if (goos->sprite[i]->life <= 0) {
            sfSprite_setPosition(goos->sprite[i]->sprite, (sfVector2f){0, 0});
            goos->sprite[i]->pos = (sfVector2f){0, 0};
            goos->sprite[i]->is_displayed = false;
            goos->sprite[i]->life = 100 + ((i - 7) / 3) * 50;
            eve[8 + (i - 7) / 3]++;
        }
    }
}