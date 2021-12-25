/*
** EPITECH PROJECT, 2021
** project zc
** File description:
** main
*/

#include <cstdio>
#include <SFML/Audio.hpp>
#include "include/project.h"

void game_loop(all_s *all)
{
    all->wndw.create(sf::VideoMode(1920, 1080), "Project ZC", sf::Style::Close);
    global_init(all);
    while (all->wndw.isOpen()) 
    {
        draw_things(all);
        all->wndw.display();
        while (all->wndw.pollEvent(all->evt))
        {
            all_events(all);
            custom_events(all);
        }
        if (all->state == gamest) {
            game_play(all);
        }
    }
}

int main(int argc, char **argv)
{
    all_s all;

    game_loop(&all);
    return (0);
}