#include <SFML/Graphics.hpp>
#include <string>
#include "Auto.h"
#include "Ball.h"

#include <ctime>
#include <cstdlib>


using namespace sf;


#define CANT_BOLITAS 500

float getRand(float min, float max) {
    float tmp = rand();
    tmp /= RAND_MAX;
    tmp *= (max - min);
    tmp += min;
    return tmp;
}


int main() {

    srand(time(NULL));


    // Create the main window
    RenderWindow window(VideoMode(800, 600), "Mi Prog");
    // Load a sprite to display
    Texture tex_auto;
    if (!tex_auto.loadFromFile("auto.png"))
        return EXIT_FAILURE;

    Texture tex_ball;
    if (!tex_ball.loadFromFile("ball.png"))
        return EXIT_FAILURE;

    Auto player(0, 0, tex_auto);

    Ball bolitas[CANT_BOLITAS];

    for (int i = 0; i < CANT_BOLITAS; ++i) {
        bolitas[i].setX(getRand(0,800));
        bolitas[i].setY(getRand(0,600));
        bolitas[i].setVelX(getRand(-5,5));
        bolitas[i].setVelY(getRand(-5,5));
        bolitas[i].setTexture(tex_ball);
    }


    // Create a graphical text to display
    Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;

    Text text("Algo", font, 50);

    // Load a music to play
//    Music music;
//    if (!music.openFromFile("nice_music.ogg"))
//        return EXIT_FAILURE;
//
//    // Play the music
//    music.play();




    window.setFramerateLimit(60);
    // Start the game loop
    while (window.isOpen()) {
        // Process events
        Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            player.mover(-5, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            player.mover(5, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            player.mover(0, -5);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            player.mover(0, 5);
        }

        for (int i = 0; i < CANT_BOLITAS; ++i) {
            bolitas[i].mover();
        }


        // Clear screen
        window.clear();
        // Draw the sprite

        for (int i = 0; i < CANT_BOLITAS; ++i) {
            bolitas[i].dibujar(window);
        }
        player.dibujar(window);

        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}