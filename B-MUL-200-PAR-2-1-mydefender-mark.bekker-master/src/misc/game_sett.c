/*
** EPITECH PROJECT, 2021
** game_sett
** File description:
** manages game settings
*/

#include <defender.h>

void init_misc(goo_s *goos)
{
    goos->font = sfFont_createFromFile("ressources/LoremIpsum.ttf");
    goos->text = sfText_create();
    sfText_setFont(goos->text, goos->font);
    sfText_setCharacterSize(goos->text, 45);
    sfText_setColor(goos->text, sfWhite);
    sfText_setPosition(goos->text, (sfVector2f){70, 5});
    goos->clock = sfClock_create();
    goos->pause = sfClock_create();
    goos->time = sfTime_Zero;
    goos->paused = sfTime_Zero;
}

void init_sett(goo_s *goos)
{
    for (int i = 7; i < 10; i++) {
        goos->sprite[i]->life = 200;
        goos->sprite[i]->speed = 0.5;
        goos->sprite[i]->is_displayed = false;
        goos->sprite[i]->focus = false;
    }
    for (int i = 10; i < 13; i++) {
        goos->sprite[i]->life = 150;
        goos->sprite[i]->speed = 1;
        goos->sprite[i]->is_displayed = false;
        goos->sprite[i]->focus = false;
    }
    for (int i = 13; i < 16; i++) {
        goos->sprite[i]->life = 100;
        goos->sprite[i]->speed = 1.5;
        goos->sprite[i]->is_displayed = false;
        goos->sprite[i]->focus = false;
    }
}

void init_pos(goo_s *goos)
{
    for (int i = 0; i < 30; i++) {
        sfSprite_setPosition(goos->sprite[i]->sprite, (sfVector2f){0, 0});
        goos->sprite[i]->pos = (sfVector2f){0, 0};
    }
    goos->sprite[0]->pos = (sfVector2f){-170, 0};
    goos->sprite[5]->pos.x = 36;
    goos->sprite[6]->pos.x = 72;
    goos->sprite[16]->pos = (sfVector2f){320, 190};
    goos->sprite[17]->pos = (sfVector2f){320, 190};
    goos->sprite[18]->pos = (sfVector2f){320, 245};
    goos->sprite[19]->pos = (sfVector2f){320, 245};
    goos->sprite[29]->pos = (sfVector2f){0, 60};
    goos->sprite[29]->rect = (sfIntRect){0, 0, 146, 132};
    sfSprite_setTextureRect(goos->sprite[29]->sprite, goos->sprite[29]->rect);
    init_sett(goos);
}