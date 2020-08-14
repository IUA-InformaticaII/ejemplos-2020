//
// Created by martin on 14/8/20.
//

#include "Auto.h"

void Auto::mover(int x, int y) {
    this->x += x;
    this->y += y;

    if (this->x < 0)
        this->x = 0;
    if (this->x > 800 - sp.getTexture()->getSize().x)
        this->x = 800 - sp.getTexture()->getSize().x;
    if (this->y < 0)
        this->y = 0;
    if (this->y > 600 - sp.getTexture()->getSize().y)
        this->y = 600 - sp.getTexture()->getSize().y;

}

void Auto::dibujar(RenderWindow &w) {
    sp.setPosition(this->x, this->y);
    w.draw(sp);
}

Auto::Auto(int x_inicial, int y_inicial, Texture &tex) {
    x = x_inicial;
    y = y_inicial;
    sp.setTexture(tex);
}
