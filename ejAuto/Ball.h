#include <SFML/Graphics.hpp>

using namespace sf;

#ifndef TDA_BALL_H
#define TDA_BALL_H


class Ball {
private:
    int x;
    int y;

    float vel_x;
    float vel_y;

    Sprite sp;
public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    float getVelX() const;

    void setVelX(float velX);

    float getVelY() const;

    void setVelY(float velY);

    void setTexture(Texture &tex);

    void mover();

    void dibujar(RenderWindow &w);
};


#endif //TDA_BALL_H
