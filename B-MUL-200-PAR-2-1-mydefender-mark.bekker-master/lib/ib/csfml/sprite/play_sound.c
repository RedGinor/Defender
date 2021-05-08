/*
** EPITECH PROJECT, 2021
** play_sound
** File description:
** plays a sound and exit
*/

#include "../../sprite.h"

void play_sound(char *path)
{
    sfMusic *tmp = sfMusic_createFromFile(path);

    sfMusic_play(tmp);
    sfMusic_destroy(tmp);
}
