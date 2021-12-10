/*
** EPITECH PROJECT, 2021
** $
** File description:
** setup_settings
*/

#include "include/project.h"

void setup_settings(all_s *all)
{
    all->stdbt[4].create_sprite("assets/Sett.png", vct2f(130, 50));
    all->stdbt[5].create_sprite("assets/flsc.png", vct2f(1000, 500), irect(0, 0, 450, 150));
    all->stdbt[5].create_text("OFF", 70, vct2f(1500, 510), sf::Color::Cyan);
    all->stdbt[6].create_sprite("assets/exit.png", vct2f(180, 720), irect(0, 0, 450, 150));
}