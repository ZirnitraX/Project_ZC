/*
** EPITECH PROJECT, 2021
** Project_Zt
** File description:
** strct
*/

#include "player.h"
#include "ball.h"

enum menu_status {
    menust = 0, settingsst, gamest, pausest
};

class sprites_s {
    sf::Font font;
    sf::Texture textur;
public:
    char *str;
    sf::Text text;
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
    void create_text(const char *strng, unsigned int char_size = 60, sf::Vector2f pos = {0, 0},
    const sf::Color &color = sf::Color::White, sf::Vector2f scale = {1, 1})
    {
        font.loadFromFile("assets/police.ttf");
        text.setFont(font);
        text.setString(strng);
        text.setCharacterSize(char_size);
        text.setPosition(pos);
        text.setFillColor(color);
        text.setScale(scale);
        str = strdup(strng);
    }
    void change_text(const char *strng)
    {
        text.setString(strng);
        str = strdup(strng);
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
    sf::Vector2f get_center(void)
    {
        sf::Vector2f result;

        result.x = sprite.getPosition().x + sprite.getGlobalBounds().width;
        result.y = sprite.getPosition().y + sprite.getGlobalBounds().height;
        return (result);
    }
};

class audio_snd {
    sf::SoundBuffer buffer;
public:
    sf::Sound sound;

    bool create_sound(const char *str)
    {
        if (!buffer.loadFromFile(str)) {
            std::cout << "fail to load the sound\n"; return false;}
        sound.setBuffer(buffer);
        return (true);
    }
};

class audio_msc {
public:
    sf::Music msc;

    bool create_music(const char *str)
    {
        if (!msc.openFromFile(str)) {std::cout << "fail to open music" << std::endl; return (false);}
    return (true);
    }
};

class text_c {
    sf::Font font;
public:
    sf::Text text;
    char *str;
    sf::Vector2f position;
    sf::Vector2f scale;
    
    void create_text(const char *strng, unsigned int char_size = 60, sf::Vector2f pos = {0, 0},
    const sf::Color &color = sf::Color::White, sf::Vector2f scale = {1, 1})
    {
        font.loadFromFile("assets/police.ttf");
        text.setFont(font);
        text.setString(strng);
        text.setCharacterSize(char_size);
        text.setPosition(pos);
        text.setFillColor(color);
        text.setScale(scale);
        str = strdup(strng);
    }
    void change_text(const char *strng)
    {
        text.setString(strng);
        str = strdup(strng);
    }
};

class menu_c {
public:
    audio_snd clik_snd;
    audio_snd clak_snd;
    sprites_s stdbt[7];
};

class all_s {
public:
    sf::Clock clock;
    sf::RenderWindow wndw;
    sf::Event evt;
    menu_c menu;
    player_c player;
    Ball_c ball;
    audio_msc music;
    menu_status state;
    sprites_s game_env[7];
};