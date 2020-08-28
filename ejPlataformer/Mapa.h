//
// Created by martin on 28/8/20.
//
#include <SFML/Graphics.hpp>

#ifndef INFO2_2020_MAPA_H
#define INFO2_2020_MAPA_H
using namespace sf;

class Mapa {
private:
    Sprite mapa[10][5];
    Texture tex_mapa;
public:
    Mapa(char archivo[]);
    void dibujar(RenderWindow &window);
};


#endif //INFO2_2020_MAPA_H
