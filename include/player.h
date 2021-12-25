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
    IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING, JUMPING_LEFT, JUMPING_RIGHT, MOVING_UP, MOVING_DOWN
};

enum LAST_HIT {
    WALL = 0, TOP, BOTTOM,
};

class player_c {
    sf::Texture texture;
public:
    sf::Vector2f position;
    sf::Vector2f scale;
    sf::Vector2f origin;
    LAST_HIT last_hit;
    PLAYER_STATE state;
    sf::Clock anim_clock;
    sf::Clock mov_clock;
    sf::Sprite sprite;
    sf::IntRect rect;
    sf::Vector2f velocity;
    bool is_moving;
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
        position = pos;
        scale = sc;
        rect = rct;
    }
    void base_init(void)
    {
        state = IDLE;
        origin = {0.f, 0.f};
        is_init = false;
        score = 0;
        is_ball = false;
        is_moving = false;
        last_hit = BOTTOM;
    }
    void move(sf::Vector2f vect)
    {
        position.x += vect.x;
        position.y += vect.y;
        sprite.setPosition(position);
    }
    void place(int x, int y)
    {
        position.x = x;
        position.y = y;
        sprite.setPosition(position);
    }
    void setScale(const float x,const float y)
    {
        sf::Vector2f scale;
        scale.x = x;
        scale.y = y;
        sprite.setScale(scale);
    }
    sf::Vector2f get_center(void)
    {
        sf::Vector2f result;

        result.x = sprite.getPosition().x + sprite.getGlobalBounds().width;
        result.y = sprite.getPosition().y + sprite.getGlobalBounds().height;
        return (result);
    }
};