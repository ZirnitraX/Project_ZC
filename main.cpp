/*
** EPITECH PROJECT, 2021
** project zc
** File description:
** main
*/

#include <cstdio>
#include "include/project.h"

void game_loop(all_s *all)
{
    all->wndw.create(sf::VideoMode(1920, 1080), "Project ZC", sf::Style::Default);
    all->state = menust;
    setup_menu(all);
    while (all->wndw.isOpen()) 
    {
        while (all->wndw.pollEvent(all->evt))
        {
            all_events(all);
        }
        all->wndw.draw(all->mnbt.sprite);
        all->wndw.display();
    }
}

int main(int argc, char **argv)
{
    all_s all;

    game_loop(&all);
    return (0);
}