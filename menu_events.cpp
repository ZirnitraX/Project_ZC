/*
** EPITECH PROJECT, 2021
** Project_Zt
** File description:
** menu_events
*/

#include "include/project.h"

void menu_actions(all_s *all, int i)
{
    switch (i) {
        case 1:
        all->state = settingsst;
        break;
        case 2:
        all->wndw.close();
        break;
        case 3:
        all->state = gamest;
        if (!all->player.is_init)
            game_init(all);
        break;
    }
    
}

void menu_events(all_s *all)
{
    for (int i = 1; i != 4; i++) {
        if (is_mouse_over(all->wndw, all->menu.stdbt[i].sprite)) {
            all->menu.stdbt[i].move_rect(150, 0, 450, 150);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                all->menu.stdbt[i].move_rect(300, 0, 450, 150);
            if (all->evt.type == sf::Event::MouseButtonPressed)
                all->menu.clik_snd.sound.play();
            } if (all->evt.type == sf::Event::MouseButtonReleased) {
                all->menu.clak_snd.sound.play();
                    menu_actions(all, i);
            }
        }
        else 
            all->menu.stdbt[i].move_rect(0, 0, 450, 150);
    }
}