/*
** EPITECH PROJECT, 2021
** lib-csfml
** File description:
** destroy_sprite
*/

#include "../../sprite.h"
#include <stdlib.h>

void destroy_sprite(sprite_s *sprite)
{
    sfSprite_destroy(sprite->sprite);
    sfTexture_destroy(sprite->texture);
    free(sprite);
}