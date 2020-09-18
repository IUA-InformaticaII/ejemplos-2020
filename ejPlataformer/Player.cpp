//
// Created by martin on 14/8/20.
//

#include "Player.h"

void Player::mover(int x, int vy) {
    this->x += x;
    this->vy += vy;

    if (this->x < 0)
        this->x = 0;
    if (this->x > 800 - sp.getTexture()->getSize().x)
        this->x = 800 - sp.getTexture()->getSize().x;
    if (this->y < 0)
        this->y = 0;
    if (this->y > 600 - sp.getTexture()->getSize().y)
        this->y = 600 - sp.getTexture()->getSize().y;

}

void Player::dibujar(RenderWindow &window) {
    static int delay = 0;
    // Gravedad

    // vf = vo + a * T
    // yf = yi + vi * t + (a * t^2)/2
    float g = 1;

    vy = vy + g;
    y = y + vy + g / 2;
    if (y > 160 - 64) {
        y = 160 - 64;
        vy = 0;
    }

    sp.setPosition(this->x, this->y);

    delay++;
    if (delay >= 30) {
        delay = 0;
        anim_actual++;
        anim_actual = anim_actual % 8;
    }

    sp.setTextureRect({anim_actual * 32, 0, 32, 32});
    window.draw(sp);
}

Player::Player(int x_inicial, int y_inicial, Texture &tex) {
    anim_actual = 0;
    x = x_inicial;
    y = y_inicial;
    vy = 0;
    sp.setTexture(tex);
}
