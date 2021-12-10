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
        all->player.create_sprite("assets/player.png", vct2f(0, 0), irect(0, 0, 95, 102), vct2f(2, 2));
    }
}