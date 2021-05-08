/*
** EPITECH PROJECT, 2021
** lib-csfml
** File description:
** create_sprite
*/

#include "../../sprite.h"
#include <stdlib.h>

sprite_s *create_sprite(char *filepath)
{
    sprite_s *sprite;

    sprite = malloc(sizeof(sprite_s));
    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sprite->sprite = sfSprite_create();
    sprite->pos = (sfVector2f){0, 0};
    sprite->size = (sfVector2f){1, 1};
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    return (sprite);
}