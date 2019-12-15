/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner
*/

#include "../lib/my/include/my.h"
#include "csfml.h"

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

//STRUCTURES

typedef struct my_clock
{
    sfClock *time_elapsed;
    sfClock *enemy_spawn_time;
    sfClock *bg_anim;
    sfClock *player_anim;
    sfClock *fireball_anim;
    sfClock *enemy_anim;
} my_clock_t;

typedef struct csfml_info
{
    sfRenderWindow *window;
    sfEvent my_event;
    my_clock_t *clock;
    sfEvent event;
} csfml_t;

typedef struct player
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f *pos;
    sfIntRect *rect;
    int hp;
    int gravity;
} player_t;

typedef struct fireball
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f *pos;
} fireball_t;

typedef struct background
{
    sfTexture *texture_back;
    sfTexture *texture_fore;
    sfSprite *sprite_back;
    sfSprite *sprite_fore;
    sfVector2f *pos_back;
    sfVector2f *pos_fore;
    struct background *next;
    struct background *prev;
} background_t;



int special_case(char *arg);
int infinite_mode(void);
int core(void);
int errors(int arg_nb, char **env);
sfRenderWindow *create_window(int width, int height);
void animate_player(csfml_t *info, player_t *player);
void move_player(csfml_t *info, player_t *player);
void disp_bg(csfml_t *info, background_t *bg);
void init_info(csfml_t *info);
sfRenderWindow *create_window(int width, int height);
void init_player(player_t *player);
void init_background(background_t *bg);
void init_foreground(background_t *bg);
int game(csfml_t *info, player_t *player, background_t *bg);
int run_game(csfml_t *info, player_t *player, background_t *bg);
void display_player(csfml_t *info, player_t *player);

#define LOSE (-1)
#define WIN (1)
#define TRUE (1)
#define FALSE (0)
#define ERROR (84)
#endif /* !MY_RUNNER_H_ */
