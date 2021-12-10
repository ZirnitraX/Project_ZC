/*
** EPITECH PROJECT, 2021
** Project_Zt
** File description:
** is_mouse_over
*/

#include "include/project.h"

bool is_mouse_over(sf::RenderWindow& wndw, sf::Sprite sprite)
{
    sf::Vector2f mous_pos = (sf::Vector2f)sf::Mouse::getPosition(wndw);
    sf::FloatRect rec = sprite.getGlobalBounds();

    if (mous_pos.x >= rec.left && mous_pos.y >= rec.top
    && mous_pos.x <= (rec.width + rec.left) && mous_pos.y <= (rec.height + rec.top))
        return (true);
    else return (false);
}