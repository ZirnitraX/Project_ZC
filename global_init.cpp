/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** global_init
*/

#include "include/project.h"

void global_init(all_s *all)
{ 
    all->wndw.setFramerateLimit(120);
    all->state = menust;
    all->clik_snd.create_sound("assets/clik.wav");
    all->clak_snd.create_sound("assets/clak.wav");
    setup_settings(all);
    setup_menu(all);
    all->player.base_init();
}