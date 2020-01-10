/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** game_parameters
*/

#ifndef GAME_PARAMETERS_H_
#define GAME_PARAMETERS_H_

#define MAX_HP (5555)
#define WINDOW_LEN (1267) //BASE LEN: 1267; MAX_LEN: 2534

#define WINDOW_HEIGHT (481)
#define BACKGROUND_IMG_LEN (2534)

#define ENEMY_HEIGHT (100)
#define ENEMY_WIDTH (135)
#define ENEMY_SPRITE_LEN (540 - ENEMY_WIDTH)

#define FIREBALL_HEIGHT (75)
#define FIREBALL_WIDTH (75)
#define FIREBALL_SPRITE_LEN (300)

#define PLAYER_HEIGHT (75)
#define PLAYER_WIDTH (75)
#define PLAYER_SPRITE_LEN (1125)
#define PLAYER_SPAWN_X (200)
#define PLAYER_SPAWN_Y (350)

#define LOSE (1)
#define CLOSE (-1)

#define T_ENEMY_SPAWN (700000)
#define T_DIFF_SCALE (100000)
#define T_ANIMATION (10000)
#define T_FIRE_RATE (700000)
#define T_SCORE_SCALE (1000000)
#define T_XP_SPAWN (8000000)

#define XP_SCORE (5)


#endif /* !GAME_PARAMETERS_H_ */
