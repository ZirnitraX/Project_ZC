/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** player
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string.h>

enum PLAYER_STATE {
    IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING, JUMPING_LEFT, JUMPING_RIGHT
};

class player_c {
    sf::Texture texture;
public:
    PLAYER_STATE state;
    sf::Vector2f scale;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::IntRect rect;
    bool is_init;
    bool is_ball;
    int score;
    
    void create_sprite(const char *str, sf::Vector2f pos = {0, 0}, const sf::IntRect rct = {0, 0, 0, 0},  sf::Vector2f sc = {1, 1})
    {
        if (!texture.loadFromFile(str)) {
            std::cout << "fail to load the texture\n";
        }
        sprite.setTexture(texture);
        sprite.setScale(sc);
        sprite.setPosition(pos);
        if (rct.height != 0 && rct.width != 0)
            sprite.setTextureRect(rct);
        scale = sc;
        position = pos;
        rect = rct;
    }
    void base_init(void)
    {
        state = IDLE;
        is_init = false;
        score = 0;
        is_ball = false;
    }
    void move(int x, int y)
    {
        position.x += x;
        position.y += y;
        sprite.setPosition(position);
    }
    void place(int x, int y)
    {
        position.x = x;
        position.y = y;
        sprite.setPosition(position);
    }
    void reverse()
    {
        scale.x *= -1;
        sprite.setScale(scale);
    }
};