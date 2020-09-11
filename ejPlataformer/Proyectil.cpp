//
// Created by martin on 11/9/20.
//

#include "Proyectil.h"

Proyectil::Proyectil(int x, int y, Texture &tex) {
    this->x = x;
    this->y = y;
    sp.setTexture(tex);
    sp.setTextureRect({0, 0, 19, 17});
}

bool Proyectil::mover() {
    this->x += 3;
    if (this->x > 320)
        return true;
    else
        return false;
}

void Proyectil::dibujar(RenderWindow &window) {
    sp.setPosition(this->x, this->y);
    window.draw(sp);
}
