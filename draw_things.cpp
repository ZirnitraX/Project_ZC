/*
** EPITECH PROJECT, 2021
** Project_Zt
** File description:
** draw_things
*/

#include "include/project.h"

void draw_menu(sprites_s *stdbt, sf::RenderWindow& wndw)
{
    for (int i = 0; i != 4; i++)
        wndw.draw(stdbt[i].sprite);
}

void draw_settings(sprites_s *stdbt, sf::RenderWindow& wndw)
{
    wndw.draw(stdbt[0].sprite);
    for (int i = 4; i != 7; i++)
        wndw.draw(stdbt[i].sprite);
    wndw.draw(stdbt[5].text);
}

void draw_game(sf::RenderWindow& wndw, player_c player, sprites_s *game, Ball_c ball)
{
    for (int i = 0; i != 7; i++)
        wndw.draw(game[i].sprite);
    wndw.draw(player.sprite);
    wndw.draw(ball.sprite);
}

void draw_things(all_s *all)
{
    all->wndw.clear();
    switch (all->state)
    {
    case menust:
        draw_menu(all->menu.stdbt, all->wndw);
        break;
    case settingsst:
        draw_settings(all->menu.stdbt, all->wndw);
        break;
    case gamest:
        draw_game(all->wndw, all->player, all->game_env, all->ball);
        break;
    }
}