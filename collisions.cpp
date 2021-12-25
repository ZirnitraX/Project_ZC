/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** collisions
*/

#include "include/project.h"

bool is_colision(player_c player, sprites_s obj)
{
    sf::Vector2f dist = {player.get_center().x - obj.get_center().x, player.get_center().y - obj.get_center().y};
    float x = std::abs(dist.x) - ((player.sprite.getGlobalBounds().height + obj.sprite.getGlobalBounds().height) / 2.0f);
    float y = std::abs(dist.y) - ((player.sprite.getGlobalBounds().width + obj.sprite.getGlobalBounds().width) / 2.0f); 

    printf("dist x = %.f, y = %.f, x = %.f, y = %.f, player w %.f h %.f\n", dist.x, dist.y, x, y, player.sprite.getGlobalBounds().width, player.sprite.getGlobalBounds().height);

    if (x < 0 && y < 0)
        return (true);
    return (false);
}