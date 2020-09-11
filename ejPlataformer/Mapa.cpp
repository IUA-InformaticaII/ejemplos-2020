#include "Mapa.h"
#include <fstream>

using namespace std;

Mapa::Mapa(char archivo[]) {
    string imagenMapa;
    int tmp;

    ifstream lectura;
    lectura.open(archivo);

    lectura >> imagenMapa;
    tex_mapa.loadFromFile(imagenMapa);

    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < 10; i++) {
            lectura >> tmp;
            int fil, col;
            col = tmp % 3;
            fil = tmp / 3;

            mapa[i][j].setTexture(tex_mapa);
            mapa[i][j].setTextureRect({col * 32, fil * 32, 32, 32});
            mapa[i][j].setPosition(i * 32, j * 32);
        }
    }
    lectura.close();
}

void Mapa::dibujar(RenderWindow &window) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; ++j) {
            window.draw(mapa[i][j]);
        }
    }
}
