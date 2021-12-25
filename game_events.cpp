/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** game_events
*/

#include "include/project.h"

void player_imputs(all_s *all)
{
    if (all->player.state == FALLING) return;
    all->player.state = IDLE;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        all->player.state = JUMPING;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
            all->player.state = JUMPING;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            all->player.state = JUMPING_RIGHT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
            all->player.state = JUMPING_LEFT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        all->player.state = MOVING_RIGHT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        all->player.state = MOVING_LEFT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {   
        all->player.state = MOVING_DOWN;
    }
}

void game_events(all_s *all)
{
    player_imputs(all);    
}