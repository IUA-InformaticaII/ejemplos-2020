#include <SFML/Graphics.hpp>

using namespace sf;

#ifndef INFO2_2020_PROYECTIL_H
#define INFO2_2020_PROYECTIL_H


class Proyectil {
private:
    int x;
    int y;
    Sprite sp;
public:
    Proyectil(int x, int y, Texture &tex);

    bool mover();

    void dibujar(RenderWindow &window);
};


#endif //INFO2_2020_PROYECTIL_H
