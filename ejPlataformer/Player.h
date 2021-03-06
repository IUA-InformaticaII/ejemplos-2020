#include <SFML/Graphics.hpp>

using namespace sf;
#ifndef TDA_AUTO_H
#define TDA_AUTO_H

class Player {
private:
    int x;
    int y;
    int vy;
    int anim_actual;
    Sprite sp;

public:
    Player(int x_inicial, int y_inicial, Texture &tex);

    void mover(int x, int y);

    void dibujar(RenderWindow &window);

    int getX(){return x;};

    int getY(){return y;};
};


#endif //TDA_AUTO_H
