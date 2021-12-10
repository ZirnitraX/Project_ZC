/*
** EPITECH PROJECT, 2021
** Project_Zt
** File description:
** project
*/

#include "my.h"
#include "strct.h"

#define vct2f sf::Vector2f
#define irect sf::IntRect

void global_init(all_s *all);

void all_events(all_s *all);
void custom_events(all_s *all);
void menu_events(all_s *all);

bool setup_menu(all_s *all);
void settings_events(all_s *all);
void setup_settings(all_s *all);

void game_events(all_s *all);
void game_init(all_s *all);

bool is_mouse_over(sf::RenderWindow& wndw, sf::Sprite sprite);
void draw_things(all_s *all);
