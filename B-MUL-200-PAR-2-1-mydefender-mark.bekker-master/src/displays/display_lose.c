/*
** EPITECH PROJECT, 2021
** display_lose
** File description:
** displays loose menu
*/

#include <defender.h>

void disp_lose(sfRenderWindow *window, goo_s *goos)
{
    display_sprite(goos->sprite[28], window, false);
}