/*
** EPITECH PROJECT, 2021
** display_extras
** File description:
** displays score, lifes and other extras
*/

#include <defender.h>
#include <stdlib.h>
#include <ib.h>

void pause_game(int *eve, goo_s *goos)
{
    goos->time = sfClock_getElapsedTime(goos->clock);
    if (eve[1]) {
        goos->paused = sfClock_getElapsedTime(goos->pause);
    } else
        sfClock_restart(goos->pause);
    goos->time.microseconds -= goos->paused.microseconds;
}

void display_time_left(sfRenderWindow *window, int *eve, goo_s *goos)
{
    int time = (int)sfTime_asSeconds(goos->time);
    int cd = 20 + !eve[7] * 20;
    char *res = malloc(sizeof(char) * 3);

    res[0] = (cd - time > 9)?((char)((cd - time) / 10) + '0'):(' ');
    res[1] = (char)((cd - time) % 10) + '0';
    res[2] = '\0';
    if (eve[6])
        sfClock_restart(goos->clock);
    pause_game(eve, goos);
    sfText_setString(goos->text, res);
    if (!eve[1])
        sfRenderWindow_drawText(window, goos->text, NULL);
    if (sfTime_asSeconds(goos->time) > sfTime_asSeconds(sfSeconds(cd))) {
        eve[7] = !eve[7];
        sfClock_restart(goos->clock);
        goos->paused = sfTime_Zero;
    }
    free(res);
}
