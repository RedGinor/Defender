/*
** EPITECH PROJECT, 2021
** lib-csfml
** File description:
** move_sprite
*/

#include "../../sprite.h"

sfVector2f get_direction(char dir, float speed)
{
    sfVector2f direction = (sfVector2f){0, 0};

    switch (dir) {
    case ('d'):
        direction.y = 1 * speed;
        break;
    case ('r'):
        direction.x = 1 * speed;
        break;
    case ('u'):
        direction.y = -1 * speed;
        break;
    case ('l'):
        direction.x = -1 * speed;
        break;
    default:
        break;
    }
    return (direction);
}

void move_sprite(sprite_s *sprite, char dir, float speed)
{
    sfVector2f direction = get_direction(dir, speed);

    sfSprite_move(sprite->sprite, direction);
    sprite->pos = sfSprite_getPosition(sprite->sprite);
}