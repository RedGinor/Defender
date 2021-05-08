/*
** EPITECH PROJECT, 2021
** lib-csfml
** File description:
** sprite
*/

#ifndef __SPRITE__
#define __SPRITE__

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdbool.h>

typedef struct sprite_t
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f size;
    sfIntRect rect;
    float speed;
    int life;
    bool is_displayed;
    bool focus;
}sprite_s;

sprite_s *create_sprite(char *filepath);
void destroy_sprite(sprite_s *sprite);
void move_sprite(sprite_s *sprite, char dir, float speed);
void display_sprite(sprite_s *sprite, sfRenderWindow *window, bool destroy);

#endif /*__SPRITE__*/