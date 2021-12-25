/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** game_init
*/

#include "include/project.h"

void game_init(all_s *all)
{
    if (!all->player.is_init) {
        all->player.create_sprite("assets/player.png", vct2f(300, 500), irect(0, 0, 95, 102), vct2f(0.7f, 0.7f));
        all->ball.create_sprite("assets/ball.png", vct2f(700, 600), irect(0, 0, 195, 200), vct2f(0.2f, 0.2f));
    }
    all->game_env[0].create_sprite("assets/gam_bck.png");
    all->game_env[1].create_sprite("assets/wall.png", vct2f(-20, 0), irect(0, 0, 0, 0), vct2f(1, 3.3));
    all->game_env[2].create_sprite("assets/wall.png", vct2f(1980, 0), irect(0, 0, 0, 0), vct2f(-1, 3.3));
    all->game_env[3].create_sprite("assets/floor.png", vct2f(0, 950), irect(0, 0, 0, 0), vct2f(1, 0.5));
    all->game_env[4].create_sprite("assets/floor.png", vct2f(0, -80), irect(0, 0, 0, 0), vct2f(1, 0.5));
    all->game_env[5].create_sprite("assets/wall.png", vct2f(950, 0), irect(0, 0, 0, 0), vct2f(0.5, 3.3));
    //all->game_env[4].create_sprite("assets/wall.png", vct2f(1950, 0), irect(0, 0, 0, 0), vct2f(-1.3, 1.45));
}