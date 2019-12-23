/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** my_runner
*/

#include "../lib/my/include/my.h"
#include "csfml.h"
#include "game_parameters.h"

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

//STRUCTURES

typedef int bool;

typedef struct my_clock
{
    sfClock *time_elapsed;
    sfClock *bg_anim;
    sfClock *player_anim;
    sfClock *fireball_as;
    sfClock *fireball_anim;
    sfClock *enemy_anim;
    sfClock *compute_score;
    sfClock *enemies_spawn;
} my_clock_t;

typedef struct csfml_info
{
    sfRenderWindow *window;
    sfEvent my_event;
    sfKeyEvent my_keyEvent;
    my_clock_t *clock;
    sfEvent event;
    sfText *txt;
} csfml_t;

typedef struct health
{
    sfTexture *texture;
    sfSprite *sprite;
    int hp;
    struct health *next;
    struct health *prev;
} health_t;

typedef struct fireball
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect *rect;
    sfVector2f *pos;
    bool used;
    struct fireball *next;
} fireball_t;

typedef struct player
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f *pos;
    sfIntRect *rect;
    float gravity;
    char *score;
    health_t *health;
    fireball_t *fireball;
} player_t;

typedef struct enemy
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f *pos;
    sfIntRect *rect;
    bool destroyed;
    struct enemy *next;
} enemy_t;

typedef struct obj
{
    player_t *player;
    enemy_t *enemy;
} obj_t;
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

//proto

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
void init_player(player_t **player);
void init_background(background_t *bg);
void init_foreground(background_t *bg);
int game(csfml_t *info, obj_t *obj, background_t *bg);
int run_game(csfml_t *info, obj_t *obj, background_t *bg);
void display_player(csfml_t *info, player_t *player);
fireball_t *init_fireball(sfVector2f *pos);
void free_all(csfml_t *info);
int game_parameters(void);
void launch_fireball(csfml_t *info, player_t *player);
void gest_player(csfml_t *info, player_t *player);
void new_fireball(fireball_t **fireball, sfVector2f *pos);
void anim_fireball(fireball_t **,  csfml_t *info);
void scale_score(csfml_t *info, player_t *player);
char *infin_add(char *score, int new_value);
void init_txt(csfml_t *info);
enemy_t *init_enemy(void);
void init_obj(obj_t *obj);
void anim_bg(csfml_t *info, background_t *bg);
void spawn_enemies(csfml_t *info, enemy_t **);
void display_fireball(csfml_t *info, fireball_t *fireball);
void anim_enemy(enemy_t **enemy,  csfml_t *info);
void display_enemy(csfml_t *info, enemy_t *enemy);
void new_enemy(enemy_t **enemy);

//defines

#define LOSE (-1)
#define WIN (1)
#define true (1)
#define false (0)
#define ERROR (84)

#endif /* !MY_RUNNER_H_ */
