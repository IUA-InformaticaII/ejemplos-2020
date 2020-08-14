#include <SFML/Graphics.hpp>

using namespace sf;
#ifndef TDA_AUTO_H
#define TDA_AUTO_H

class Auto {
private:
    int x;
    int y;
    Sprite sp;

public:
    Auto(int x_inicial, int y_inicial, Texture &tex);

    void mover(int x, int y);

    void dibujar(RenderWindow &w);
};


#endif //TDA_AUTO_H
