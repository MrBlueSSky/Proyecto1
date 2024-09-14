#include "Jugador.h"
#include <iostream>  // Para imprimir mensajes de depuración

// Constructor del Jugador
Jugador::Jugador(int x, int y, Tablero* tablero) : posX(x), posY(y), tablero(tablero) {}

// Mover el jugador en la dirección especificada
void Jugador::mover(char direccion) {
    // Convertir la dirección a mayúsculas si es necesario
    direccion = toupper(direccion);

    int nuevaX = posX;
    int nuevaY = posY;

    // Definir el movimiento según la dirección
    switch (direccion) {
    case 'W': nuevaX--; break;  // Mover hacia arriba
    case 'S': nuevaX++; break;  // Mover hacia abajo
    case 'A': nuevaY--; break;  // Mover hacia la izquierda
    case 'D': nuevaY++; break;  // Mover hacia la derecha
    default:
        std::cout << "Tecla inválida. Use W, A, S o D para moverse." << std::endl;
        return;
    }

    // Imprimir el movimiento que se intenta realizar
    std::cout << "Intentando mover a (" << nuevaX << ", " << nuevaY << ")" << std::endl;

    // Verificar si el movimiento es posible
    if (puedeMover(nuevaX, nuevaY)) {
        Nodo* nodoActual = tablero->obtenerNodo(posX, posY);
        Nodo* nodoNuevo = tablero->obtenerNodo(nuevaX, nuevaY);

        // Intercambiar posiciones
        nodoNuevo->simbolo = '@';
        nodoActual->simbolo = ' ';
        posX = nuevaX;
        posY = nuevaY;

        std::cout << "Movimiento realizado a (" << nuevaX << ", " << nuevaY << ")" << std::endl;
    }
    else {
        std::cout << "Movimiento no permitido hacia (" << nuevaX << ", " << nuevaY << ")" << std::endl;
    }
}

// Verificar si el jugador puede moverse a una nueva posición
bool Jugador::puedeMover(int nuevaX, int nuevaY) {
    Nodo* destino = tablero->obtenerNodo(nuevaX, nuevaY);
    if (!destino) {
        std::cout << "Nodo no existe en la posición (" << nuevaX << ", " << nuevaY << ")" << std::endl;
        return false;
    }

    if (destino->simbolo == '#') {
        std::cout << "Pared encontrada en (" << nuevaX << ", " << nuevaY << ")" << std::endl;
        return false;
    }

    return true;  // Movimiento permitido si no es una pared
}
