//
// Created by martin on 14/8/20.
//

#include "Ball.h"

void Ball::mover() {

    this->x = this->x + vel_x;
    this->y = this->y + vel_y;

    if (this->x < 0) {
        this->x = 0;
        vel_x *= -1;
    }
    if (this->x > 800 - sp.getTexture()->getSize().x) {
        this->x = 800 - sp.getTexture()->getSize().x;
        vel_x *= -1;
    }

    if (this->y < 0) {
        this->y = 0;
        vel_y *= -1;
    }
    if (this->y > 600 - sp.getTexture()->getSize().y) {
        this->y = 600 - sp.getTexture()->getSize().y;
        vel_y *= -1;
    }
}

void Ball::dibujar(RenderWindow &w) {
    sp.setPosition(this->x, this->y);
    w.draw(sp);
}

int Ball::getX() const {
    return x;
}

void Ball::setX(int x) {
    this->x = x;
}

int Ball::getY() const {
    return y;
}

void Ball::setY(int y) {
    this->y = y;
}

float Ball::getVelX() const {
    return vel_x;
}

void Ball::setVelX(float velX) {
    vel_x = velX;
}

float Ball::getVelY() const {
    return vel_y;
}

void Ball::setVelY(float velY) {
    vel_y = velY;
}

void Ball::setTexture(Texture &tex) {
    sp.setTexture(tex);
}


