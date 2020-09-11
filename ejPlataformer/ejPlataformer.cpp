#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Mapa.h"
#include "Proyectil.h"
#include "Arreglo.h"
#include <iostream>

using namespace sf;

int main() {
    // Create the main window
    RenderWindow window(VideoMode(320, 160), "Mi Prog");
    // Load a sprite to display
    Texture tex_player;
    if (!tex_player.loadFromFile("player.png")) {
        std::cout << "No se puedo cargar player.png, verifique el WorkinDir" << std::endl;
        return EXIT_FAILURE;
    }    // Load a sprite to display

    Texture tex_proyectil;
    if (!tex_proyectil.loadFromFile("proyectil.png")) {
        std::cout << "No se puedo cargar proyectil.png, verifique el WorkinDir" << std::endl;
        return EXIT_FAILURE;
    }

    Player player(0, 0, tex_player);

    Arreglo proy;
    for (int i = 0; i < proy.getSize(); i++) {
        proy.setProyectil(i, nullptr);
    }

    Mapa map("mapa.txt");


    window.setFramerateLimit(30);
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
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            int i;
            for (i = 0; i < proy.getSize(); ++i) {
                if (proy.getProyectil(i) == nullptr) {
                    Proyectil *tmp = new Proyectil(player.getX() + 32, player.getY() + 5, tex_proyectil);
                    proy.setProyectil(i, tmp);
                    break;
                }
            }
            if (i == proy.getSize()) { // me quedé sin lugar, duplico.
                proy.duplicar();
                Proyectil *tmp = new Proyectil(player.getX() + 32, player.getY() + 5, tex_proyectil);
                proy.setProyectil(i, tmp);
            }
        }

        for (int i = 0; i < proy.getSize(); ++i) {
            if (proy.getProyectil(i) != nullptr) {
                if (proy.getProyectil(i)->mover()) {
                    delete proy.getProyectil(i);
                    proy.setProyectil(i, nullptr);
                }
            }
        }

        // Clear screen
        window.clear();
        // Draw the sprite
        map.dibujar(window);
        player.dibujar(window);

        for (int i = 0; i < proy.getSize(); ++i) {
            if (proy.getProyectil(i) != nullptr) {
                proy.getProyectil(i)->dibujar(window);
            }
        }

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}