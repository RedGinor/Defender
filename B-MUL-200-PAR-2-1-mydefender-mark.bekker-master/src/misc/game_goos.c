/*
** EPITECH PROJECT, 2021
** game_goos
** File description:
** initiates goos for the game
*/

#include <defender.h>
#include <stdlib.h>

void init_misc(goo_s *goos);
void init_pos(goo_s *goos);

void clear_goos(goo_s *goos)
{
    sfText_destroy(goos->text);
    sfClock_destroy(goos->clock);
    sfClock_destroy(goos->pause);
    sfFont_destroy(goos->font);
    for (int i = 0; i < 30; i++)
        destroy_sprite(goos->sprite[i]);
    free(goos);
}

void init_goos(goo_s *goos)
{
    goos->sprite[20] = create_sprite("ressources/set.png");
    goos->sprite[21] = create_sprite("ressources/b_off.png");
    goos->sprite[22] = create_sprite("ressources/b_on.png");
    goos->sprite[23] = create_sprite("ressources/goo.png");
    goos->sprite[24] = create_sprite("ressources/mig.png");
    goos->sprite[25] = create_sprite("ressources/tuto.png");
    goos->sprite[26] = create_sprite("ressources/mst.png");
    goos->sprite[27] = create_sprite("ressources/mouse.png");
    goos->sprite[28] = create_sprite("ressources/lose.png");
    goos->sprite[29] = create_sprite("ressources/wizard.png");
}

void initiate_goos(goo_s *goos)
{
    init_misc(goos);
    goos->sprite = malloc(sizeof(sprite_s *) * 30);
    goos->sprite[0] = create_sprite("ressources/door.png");
    goos->sprite[1] = create_sprite("ressources/eau3.png");
    goos->sprite[2] = create_sprite("ressources/eau2.png");
    goos->sprite[3] = create_sprite("ressources/eau1.png");
    for (int i = 4; i < 7; i++)
        goos->sprite[i] = create_sprite("ressources/heart.png");
    for (int i = 7; i < 10; i++)
        goos->sprite[i] = create_sprite("ressources/gooXred.png");
    for (int i = 10; i < 13; i++)
        goos->sprite[i] = create_sprite("ressources/gooXvert.png");
    for (int i = 13; i < 16; i++)
        goos->sprite[i] = create_sprite("ressources/gooXwhite.png");
    goos->sprite[16] = create_sprite("ressources/on.png");
    goos->sprite[17] = create_sprite("ressources/off.png");
    goos->sprite[18] = create_sprite("ressources/on.png");
    goos->sprite[19] = create_sprite("ressources/off.png");
    init_goos(goos);
    init_pos(goos);
}