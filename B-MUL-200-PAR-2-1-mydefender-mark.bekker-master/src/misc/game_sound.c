/*
** EPITECH PROJECT, 2021
** user_action.c
** File description:
** user_actions
*/

#include <defender.h>

void initiate_sound(sound_s *sound)
{
    sound->menu = sfMusic_createFromFile("ressources/music_theme.ogg");
    sound->game = sfMusic_createFromFile("ressources/game_theme.ogg");
    sound->mouse = sfMusic_createFromFile("ressources/mouse.ogg");
    sfMusic_setLoop(sound->menu, true);
    sfMusic_setLoop(sound->game, true);
}

void clear_sound(sound_s *sound)
{
    sfMusic_destroy(sound->menu);
    sfMusic_destroy(sound->game);
    sfMusic_destroy(sound->mouse);
}

void play_sfx(sfEvent event, sound_s *music)
{
    if (event.type == sfEvtMouseButtonPressed)
        sfMusic_play(music->mouse);
}

void play_music(sound_s *music, int *eve)
{
    sfSoundStatus m_status = sfMusic_getStatus(music->menu);
    sfSoundStatus g_status = sfMusic_getStatus(music->game);

    if (eve[5]) {
        sfMusic_stop(music->menu);
        sfMusic_stop(music->game);
    }
    if (!eve[2] && !eve[5] && m_status == sfStopped) {
        sfMusic_stop(music->game);
        sfMusic_play(music->menu);
    }
    if (eve[2] && !eve[5] && g_status == sfStopped) {
        sfMusic_stop(music->menu);
        sfMusic_play(music->game);
    }
}