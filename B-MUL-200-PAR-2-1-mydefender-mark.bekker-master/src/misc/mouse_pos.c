/*
** EPITECH PROJECT, 2021
** mouse_pos
** File description:
** checks mouse position
*/

#include <defender.h>
#include <math.h>

sfVector2i get_v(int x, int y)
{
    sfVector2i res = (sfVector2i){x, y};

    return (res);
}

bool is_ch(sfVector2i pos, sfVector2i center, int size)
{
    sfVector2i res;

    res.x = pos.x - center.x;
    res.y = pos.y - center.y;
    if (sqrt(pow(res.x, 2) + pow(res.y, 2)) <= size)
        return (true);
    return (false);
}

bool is_sh(sfVector2i pos, sfVector2i start, sfVector2i stop)
{
    if ((pos.x > start.x && pos.x < stop.x) &&
        (pos.y > start.y && pos.y < stop.y))
        return (true);
    return (false);
}