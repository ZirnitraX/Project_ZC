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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        all->player.state = JUMPING;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            all->player.state = JUMPING_RIGHT;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
            all->player.state = JUMPING_LEFT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        all->player.state = MOVING_RIGHT;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        all->player.state = MOVING_LEFT;
    }
}

void game_events(all_s *all)
{
    PLAYER_STATE buff = all->player.state;
    //if (all->evt.type == all->evt.KeyPressed)
    player_imputs(all);
    if (all ->player.state == MOVING_LEFT) {
        if (buff != all->player.state)
            all->player.reverse();
        all->player.move(-7, 0);
    } if (all ->player.state == MOVING_RIGHT)
        all->player.move(7, 0);
    
}