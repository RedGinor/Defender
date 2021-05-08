/*
** EPITECH PROJECT, 2021
** defender
** File description:
** project's headers
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include <sprite.h>

typedef struct sound_t
{
    sfMusic *menu;
    sfMusic *mouse;
    sfMusic *game;
    bool is_sound;
    bool is_sfx;
}sound_s;

typedef struct goo_t
{
    sprite_s **sprite;
    sfClock *clock;
    sfClock *pause;
    sfTime time;
    sfTime paused;
    sfText *text;
    sfFont *font;
}goo_s;

sfVector2i get_v(int x, int y);
void display_window(sfRenderWindow *window, sound_s *music, goo_s *goos);
void check_event(sfEvent t_e, sfRenderWindow *wd, int *eve, goo_s *goos);
void display_time_left(sfRenderWindow *window, int *eve, goo_s *goos);
void disp_wizard(sfRenderWindow *window, int *eve, goo_s *goos);
void disp_lives(sfRenderWindow *window, int *eve, goo_s *goos);
void play_game(sfRenderWindow *window, int *eve, goo_s *goos);
void disp_menu(sfRenderWindow *window, int *eve, goo_s *goos);
void disp_game(sfRenderWindow *window, int *eve, goo_s *goos);
void disp_lose(sfRenderWindow *window, goo_s *goos);
void disp_goo(sfRenderWindow *window, goo_s *goos);
void play_sfx(sfEvent event, sound_s *music);
void set_display_goo(int *eve, goo_s *goos);
void play_music(sound_s *music, int *eve);
void initiate_sound(sound_s *sound);
void clear_sound(sound_s *sound);
void initiate_goos(goo_s *goos);
void clear_goos(goo_s *goos);
void init_misc(goo_s *goos);
void init_pos(goo_s *goos);
void reset_eve(int *eve);
bool is_sh(sfVector2i pos, sfVector2i start, sfVector2i stop);
bool is_ch(sfVector2i pos, sfVector2i center, int size);
bool error_handler(int ac);
int rule(char **argv);

#endif
