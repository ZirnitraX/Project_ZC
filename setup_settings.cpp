/*
** EPITECH PROJECT, 2021
** $
** File description:
** setup_settings
*/

#include "include/project.h"

void setup_settings(all_s *all)
{
    all->menu.stdbt[4].create_sprite("assets/Sett.png", vct2f(130, 50));
    all->menu.stdbt[5].create_sprite("assets/flsc.png", vct2f(1200, 450), irect(0, 0, 450, 150), vct2f(0.8, 0.8));
    all->menu.stdbt[5].create_text("OFF", 70, vct2f(1600, 460), sf::Color::Cyan, vct2f(0.7f, 0.7f));
    all->menu.stdbt[6].create_sprite("assets/exit.png", vct2f(140, 810), irect(0, 0, 450, 150));
}