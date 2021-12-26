/*
** EPITECH PROJECT, 2021
** Project_ZC
** File description:
** game_play
*/

#include "include/project.h"

void animations_update(all_s *all)
{
    if (all->player.last_hit == TOP) {
        all->player.scale.y = -0.8f;
        all->player.origin.y = all->player.sprite.getGlobalBounds().height / 0.8f;
    } else if (all->player.last_hit == BOTTOM) {
        all->player.scale.y = 0.8f;
        all->player.origin.y = 0.f;
        }
    if (all->player.state == IDLE) {
        if (all->player.anim_clock.getElapsedTime().asMilliseconds() >= 200 || all->player.is_moving == true) {
            all->player.rect.top = 0;
            if (all->player.rect.left >= 285)
                all->player.rect.left = 0;
            else
                all->player.rect.left += 95;
            all->player.sprite.setTextureRect(all->player.rect);
            all->player.anim_clock.restart();
            all->player.is_moving = false;
        }
    } else if (all->player.state == MOVING_LEFT || all->player.state == MOVING_RIGHT) {
        if (all->player.state == MOVING_LEFT) {
            all->player.scale.x = -0.8f;
            all->player.origin.x = all->player.sprite.getGlobalBounds().width / 0.8f;
        } else if (all->player.state == MOVING_RIGHT) {
            all->player.scale.x = 0.8f;
            all->player.origin.x = 0.f;
        }
        if (all->player.anim_clock.getElapsedTime().asMilliseconds() >= 60 || all->player.is_moving == false) {
                all->player.rect.top = 102;
                if (all->player.rect.left >= 475)
                    all->player.rect.left = 0;
                else
                    all->player.rect.left += 95;
            all->player.sprite.setTextureRect(all->player.rect);
            all->player.is_moving = true;
            all->player.anim_clock.restart();
        }
    }
    all->player.sprite.setOrigin(all->player.origin);
    all->player.sprite.setScale(all->player.scale);
}

void player_movements(player_c *player)
{
    if (player->mov_clock.getElapsedTime().asMilliseconds() > 12.f) {
        switch (player->state)
        {
        case MOVING_LEFT:
            player->velocity = {-23.f, 0.f};
            break;
        case MOVING_RIGHT:
            player->velocity = {23.f, 0.f};
            break;
        case IDLE:
            player->velocity = {0.f, 0.f};
            break;
        case JUMPING:
            if (player->last_hit == BOTTOM)
                player->velocity = {0.f, -34.f};
            else if (player->last_hit == TOP)
                player->velocity = {0.f, 34.f};
            player->state = FALLING;
            break;
        case JUMPING_LEFT:
            if (player->last_hit == BOTTOM)
                player->velocity = {-34.f, -34.f};
            else if (player->last_hit == TOP)
                player->velocity = {-34.f, 34.f};
            player->state = FALLING;
            break;
        case JUMPING_RIGHT:
            if (player->last_hit == BOTTOM)
                player->velocity = {34.f, -34.f};
            else if (player->last_hit == TOP)
                player->velocity = {34.f, 34.f};
            player->state = FALLING;
            break;
        }
        player->mov_clock.restart();
        player->move(player->velocity);
    }

}

void player_collision(player_c *player, sprites_s *game_env, Ball_c *ball, sf::Event evt)
{
    for (int i = 1; i != 6; i++) {
        if (player->sprite.getGlobalBounds().intersects(game_env[i].sprite.getGlobalBounds())) {
            if (i == 4 || i == 3) {
                player->move(-player->velocity);
                player->state = IDLE;
            } else {
                player->move(-player->velocity);
                player->velocity.x = 0.f;
            }
            if (i == 3){
                player->last_hit = BOTTOM;
                }
            else if (i == 4){
                player->last_hit = TOP;
                }
            break;
        }
    }
    if (player->is_ball == false && evt.type == sf::Event::MouseButtonPressed)
        if (player->sprite.getGlobalBounds().intersects(ball->sprite.getGlobalBounds())) {
            player->is_ball = true;
            ball->acceleration = 1.f;
        }
}

void ball_collision(Ball_c *ball, sprites_s *game_env)
{
    for (int i = 1; i != 5; i++) {
        if (ball->sprite.getGlobalBounds().intersects(game_env[i].sprite.getGlobalBounds())) {
            ball->movebck();
            if (ball->acceleration < 13.f)    
                ball->acceleration += 0.2f;
            if (i == 3 || i == 4)
                ball->velocity.y *= -1;
            else
                ball->velocity.x *= -1;
        }
    }
}

void game_play(all_s *all)
{
    animations_update(all);
    player_movements(&all->player);
    player_collision(&all->player, all->game_env, &all->ball, all->evt);
    if (all->player.is_ball == true) {
        all->ball.place(all->player.position);
        if (all->evt.type == sf::Event::MouseButtonReleased)
            all->player.is_ball = false;
            all->ball.velocity = {11.f, 11.f};
            all->ball.acceleration = 1.f;
    }
    printf("%.2f\n", all->ball.acceleration);
    if (all->player.is_ball == false) {
        all->ball.move();
        ball_collision(&all->ball, all->game_env);
    }
}