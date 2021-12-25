/*
** EPITECH PROJECT, 2021
** Project_Zt
** File description:
** setup_menu
*/

#include "include/project.h"

bool setup_menu(all_s *all)
{
    all->menu.stdbt[0].create_sprite("assets/menu.png", vct2f(0, 0), irect(0, 0, 1920, 1080));
    all->menu.stdbt[1].create_sprite("assets/sett.png", vct2f(110, 520), irect(0, 0, 450, 150));
    all->menu.stdbt[2].create_sprite("assets/exit.png", vct2f(110, 720), irect(0, 0, 450, 150));
    all->menu.stdbt[3].create_sprite("assets/play.png", vct2f(1110, 600), irect(0, 0, 450, 150));
    return (true);
}