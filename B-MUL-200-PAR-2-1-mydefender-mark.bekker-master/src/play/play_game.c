/*
** EPITECH PROJECT, 2021
** play_game
** File description:
** plays game
*/

#include <defender.h>

void manage_turrets(sfRenderWindow *window, int *eve, goo_s *goos)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(window);

    if (eve[14] != 0)
        goos->sprite[28 + eve[14]]->pos = (sfVector2f){tmp.x - 50, tmp.y - 100};
    if (!eve[1])
        disp_wizard(window, eve, goos);
}

void manage_goos(sfRenderWindow *window, int *eve, goo_s *goos)
{
    int time = (int)sfTime_asSeconds(goos->time);
    static bool display = true;

    disp_goo(window, goos);
    if (time % (5 - eve[12]) == 4 - eve[12] && time < 25)
        display = true;
    if (display && time % (5 - eve[12]) == 0)
        set_display_goo(eve, goos);
    if (time % (5 - eve[12]) == 0)
        display = false;
}

void manage_ressources(sfRenderWindow *window, int *eve, goo_s *goos)
{
    if (!eve[6] && !eve[1] && eve[7]) {
        display_sprite(goos->sprite[0], window, false);
        if (goos->sprite[0]->pos.x > -170)
            move_sprite(goos->sprite[0], 'l', 1);
    }
    if (!eve[6] && !eve[1] && !eve[7]) {
        display_sprite(goos->sprite[0], window, false);
        if (goos->sprite[0]->pos.x < 0)
            move_sprite(goos->sprite[0], 'r', 1);
    }
}

void play_game(sfRenderWindow *window, int *eve, goo_s *goos)
{
    manage_ressources(window, eve, goos);
    if (!eve[7] && !eve[1])
        manage_goos(window, eve, goos);
    manage_turrets(window, eve, goos);
    display_time_left(window, eve, goos);
    disp_lives(window, eve, goos);
}