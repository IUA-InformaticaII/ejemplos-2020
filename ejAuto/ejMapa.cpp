#include <SFML/Graphics.hpp>
#include "Auto.h"
#include <iostream>

using namespace sf;

int main() {
    float ruta_y = 0;
    // Create the main window
    RenderWindow window(VideoMode(800, 600), "Mi Prog");
    // Load a sprite to display
    Texture tex_auto;
    if (!tex_auto.loadFromFile("auto.png")) {
        std::cout << "No se puedo cargar auto.png, verifique el WorkinDir" << std::endl;
        return EXIT_FAILURE;
    }
    Texture tex_ruta;
    if (!tex_ruta.loadFromFile("ruta.png")) {
        std::cout << "No se puedo cargar ruta.png, verifique el WorkinDir" << std::endl;
        return EXIT_FAILURE;
    }
    Sprite sp_ruta;
    Sprite sp_ruta2;
    sp_ruta.setTexture(tex_ruta);
    sp_ruta2.setTexture(tex_ruta);

    Player player(0, 0, tex_auto);

    // Create a graphical text to display
    Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;

    Text text("Algo", font, 50);

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

        ruta_y+= 3.5;

        if (ruta_y > tex_ruta.getSize().y) {
            ruta_y -= tex_ruta.getSize().y;
        }
        sp_ruta.setPosition(0, ruta_y);
        sp_ruta2.setPosition(0, ruta_y - tex_ruta.getSize().y);


        // Clear screen
        window.clear();
        window.draw(sp_ruta2);
        window.draw(sp_ruta);
        // Draw the sprite
        player.dibujar(window);
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}