#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Mapa.h"
#include <iostream>

using namespace sf;

int main() {
    float ruta_y = 0;
    // Create the main window
    RenderWindow window(VideoMode(320, 160), "Mi Prog");
    // Load a sprite to display
    Texture tex_auto;
    if (!tex_auto.loadFromFile("player.png")) {
        std::cout << "No se puedo cargar auto.png, verifique el WorkinDir" << std::endl;
        return EXIT_FAILURE;
    }
    Texture tex_ruta;
    if (!tex_ruta.loadFromFile("mapa.png")) {
        std::cout << "No se puedo cargar ruta.png, verifique el WorkinDir" << std::endl;
        return EXIT_FAILURE;
    }

    Player player(0, 0, tex_auto);
    Mapa map("mapa.txt");


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

        ruta_y += 3.5;

        if (ruta_y > tex_ruta.getSize().y) {
            ruta_y -= tex_ruta.getSize().y;
        }


        // Clear screen
        window.clear();
        // Draw the sprite
        map.dibujar(window);
        player.dibujar(window);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}