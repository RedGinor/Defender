/*
** EPITECH PROJECT, 2021
** display_sprite
** File description:
** displays sprite
*/

#include "../../sprite.h"
#include <stdlib.h>

void display_sprite(sprite_s *sprite, sfRenderWindow *window, bool destroy)
{
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
    sfSprite_scale(sprite->sprite, sprite->size);
    if (destroy)
        destroy_sprite(sprite);
}