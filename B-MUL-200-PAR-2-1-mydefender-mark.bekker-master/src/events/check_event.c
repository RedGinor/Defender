/*
** EPITECH PROJECT, 2021
** check_event
** File description:
** checks events
*/

#include <defender.h>

void reset_eve(int *eve)
{
    for (int i = 0; i < 5; i++)
        eve[i] = 0;
    for (int i = 6; i < 8; i++)
        eve[i] = 0;
    for (int i = 8; i < 12; i++)
        eve[i] = 3;
    eve[12] = 0;
    eve[13] = 0;
    eve[14] = 0;
}

void check_sett(int *eve, sfVector2i pos)
{
    if (is_ch(pos, get_v(600, 125), 30))
        eve[3] = false;
    if (is_ch(pos, get_v(345, 250), 22))
        eve[4] = !eve[4];
    if (is_ch(pos, get_v(345, 300), 22))
        eve[5] = !eve[5];
    if (!eve[2] && is_sh(pos, get_v(320, 400), get_v(380, 430)))
        eve[12] = !eve[12];
}

void check_game(int *eve, sfVector2i pos, bool p, sfEvent t_e)
{
    if (p && is_ch(pos, get_v(780, 580), 40))
        eve[1] = true;
    if (t_e.type == sfEvtKeyPressed && t_e.key.code == sfKeyEscape)
        eve[1] = true;
    if (p && is_sh(pos, get_v(10, 205), get_v(70, 225)) && eve[7])
        eve[14] = 1;
    if (p && is_sh(pos, get_v(90, 205), get_v(150, 225)) && eve[7])
        eve[14] = 2;
    if (p && is_sh(pos, get_v(10, 355), get_v(70, 375)) && eve[7])
        eve[14] = 3;
    if (p && is_sh(pos, get_v(90, 355), get_v(150, 375)) && eve[7])
        eve[14] = 4;
    if (p && eve[14] != 0 && is_sh(pos, get_v(250, 50), get_v(400, 500)))
        eve[14] = 0;
}

void check_menu(int *eve, sfVector2i pos, goo_s *goos)
{
    if (is_sh(pos, get_v(0, 0), get_v(800, 200)) || eve[13]) {
        reset_eve(eve);
        init_pos(goos);
        goos->time = sfTime_Zero;
        goos->paused = sfTime_Zero;
    }
    if (is_sh(pos, get_v(0, 200), get_v(800, 400)) && !eve[13]) {
        eve[1] = false;
        eve[6] = (eve[2])?(eve[6]):(true);
        eve[7] = (eve[2])?(eve[7]):(true);
        eve[2] = true;
    }
    if (is_sh(pos, get_v(0, 400), get_v(800, 600)) && !eve[13])
        eve[3] = true;
}

void check_event(sfEvent t_e, sfRenderWindow *wd, int *eve, goo_s *goos)
{
    bool p = (t_e.type == sfEvtMouseButtonPressed);
    sfVector2i pos = sfMouse_getPositionRenderWindow(wd);

    eve[0] = (eve[2] && p);
    if (t_e.type == sfEvtClosed || (!eve[2] && p && is_ch(pos, get_v(65, 175), 40)))
        sfRenderWindow_close(wd);
    if (p && (!eve[2] || eve[1]) && !eve[3])
        check_menu(eve, pos, goos);
    if (eve[2] && !eve[1] && !eve[13])
        check_game(eve, pos, p, t_e);
    if (p && eve[3] && !eve[13])
        check_sett(eve, pos);
}