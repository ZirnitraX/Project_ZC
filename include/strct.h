/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** strct
*/

#include <SFML/Graphics.hpp>
#include <iostream>

enum menu_status {
    menust = 0, settingsst, gamest, pausest
};

class sprites_s {
    sf::Texture textur;
    sf::Text text;
public:
    sf::Vector2f scale;
    sf::Vector2f position;
    sf::IntRect rect;
    sf::Sprite sprite;
    
    void create_sprite(const char *str, sf::Vector2f pos = {0, 0}, const sf::IntRect rct = {0, 0, 1920, 1080},  sf::Vector2f sc = {1, 1})
    {
        if (!textur.loadFromFile(str, rct)) {
            std::cout << "fail to load the tecture\n";
        }
        sprite.setTexture(textur);
        sprite.setScale(sc);
        sprite.setPosition(pos);
        scale = sc;
        position = pos;
        rect = rct;
    }

    void change_scale(float x, float y)
    {
        scale.x = x;
        scale.y = y;
        sprite.setScale(scale);
    }

    void move(float x, float y)
    {
        position.x += x;
        position.y += y;
        sprite.setPosition(position);
    }
};

class all_s {
public:
    sf::Clock clock;
    sf::RenderWindow wndw;
    sf::Event evt;
    sprites_s mnbt;
    menu_status state;
};