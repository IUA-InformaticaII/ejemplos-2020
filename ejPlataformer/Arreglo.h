//
// Created by martin on 11/9/20.
//

#ifndef INFO2_2020_ARREGLO_H
#define INFO2_2020_ARREGLO_H


#include "Proyectil.h"

class Arreglo {
private:
    Proyectil **proy;
    int size;
public:
    Arreglo() {
        proy = new Proyectil *[3];
        size = 3;
    }

    int getSize() { return size; }

    Proyectil *getProyectil(int i) {
        return proy[i];
    }

    void setProyectil(int i, Proyectil *p) {
        proy[i] = p;
    }

    void duplicar() {
        Proyectil **tmp, **toDelete;
        tmp = new Proyectil *[size * 2];
        for (int i = 0; i < size; ++i) {
            tmp[i] = proy[i];
        }
        toDelete = proy;
        proy = tmp;
        delete toDelete;
        for (int i = size; i < size * 2; ++i) {
            proy[i] = nullptr;
        }
        size = size * 2;
    }
};


#endif //INFO2_2020_ARREGLO_H
