/*
** EPITECH PROJECT, 2020
** MUL_my_runner_2019
** File description:
** collision_sound
*/

#include <SFML/Audio.h>

void set_music_xp(sfSound *destroyed)
{
    sfSoundBuffer *d_buffer = sfSoundBuffer_createFromFile("./data/Prout.wav");

    if (destroyed != NULL)
        sfSound_destroy(destroyed);
    destroyed = sfSound_create();
    sfSound_setBuffer(destroyed, d_buffer);
    sfSound_play(destroyed);
}

void set_music_collision(sfSound *hited)
{
    sfSoundBuffer *h_buffer = NULL;

    if (hited != NULL)
        sfSound_destroy(hited);
    hited = sfSound_create();
    h_buffer = sfSoundBuffer_createFromFile("./data/hit_by_enemy.wav");
    sfSound_setBuffer(hited, h_buffer);
    sfSound_play(hited);
}