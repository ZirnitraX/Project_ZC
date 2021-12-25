/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** settings_events
*/

#include "include/project.h"

void full_screen(all_s *all)
{
    all->wndw.close();
    if (strcmp(all->menu.stdbt[5].str,"OFF\0") == 0) {
        all->menu.stdbt[5].change_text("ON");
        all->wndw.create(sf::VideoMode(1920, 1080), "Project ZC", sf::Style::Fullscreen);
        all->wndw.setFramerateLimit(60);
    } else {
        all->menu.stdbt[5].change_text("OFF");
        all->wndw.create(sf::VideoMode(1920, 1080), "Project ZC", sf::Style::Close);
        all->wndw.setFramerateLimit(60);
    }
}

void settings_actions(all_s *all, int i)
{
    switch (i) {
        case 5:
        full_screen(all);
        break;
        case 6:
        all->state = menust;
    }
}

void settings_events(all_s *all)
{
    for (int i = 5; i != 7; i++) {
        if (is_mouse_over(all->wndw, all->menu.stdbt[i].sprite)) {
            all->menu.stdbt[i].move_rect(150, 0, 450, 150);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                all->menu.stdbt[i].move_rect(300, 0, 450, 150);
            if (all->evt.type == sf::Event::MouseButtonPressed)
                all->menu.clik_snd.sound.play();
            } if (all->evt.type == sf::Event::MouseButtonReleased) {
                    all->menu.clak_snd.sound.play();
                    settings_actions(all, i);
            }
        }
        else 
            all->menu.stdbt[i].move_rect(0, 0, 450, 150);
    }
}