/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** ball
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string.h>

class Ball_c {
    sf::Texture textur;
public:
    sf::Vector2f scale;
    sf::Vector2f position;
    sf::IntRect rec;
    sf::Sprite sprite;
    
    void create_sprite(const char *str, sf::Vector2f pos = {0, 0}, const sf::IntRect rct = {0, 0, 0, 0},  sf::Vector2f sc = {1, 1})
    {
        if (!textur.loadFromFile(str)) {
            std::cout << "fail to load the tecture\n";
        }
        sprite.setTexture(textur);
        sprite.setScale(sc);
        sprite.setPosition(pos);
        if (rct.height != 0 && rct.width != 0)
            sprite.setTextureRect(rct);
        scale = sc;
        position = pos;
        rec = rct;
    }
    void move_rect(int t, int l, int w, int h)
    {
        rec.top = t;
        rec.left = l;
        rec.width = w;
        rec.height = h;
        sprite.setTextureRect(rec);
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
    void place(sf::Vector2f toset) {
        sprite.setPosition(toset);
        position = toset;
    }
    sf::Vector2f get_center(void)
    {
        sf::Vector2f result;

        result.x = sprite.getPosition().x + sprite.getGlobalBounds().width;
        result.y = sprite.getPosition().y + sprite.getGlobalBounds().height;
        return (result);
    }
};
