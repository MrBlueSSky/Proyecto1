// Juego.cpp
#include "Juego.h"
#include <iostream>
#include <fstream>

// Constructor del Juego
Juego::Juego() : nivelActual(1) {
    tablero = new Tablero(10, 10);  // Crear un tablero de 10x10
    jugador = new Jugador(1, 1, tablero);  // Posición inicial del jugador
}

// Iniciar el juego
void Juego::iniciarJuego() {
    tablero->cargarNivel("nivel1.txt");
    tablero->imprimir();
    char direccion;
    while (true) {
        std::cout << "Mover (WASD): ";
        std::cin >> direccion;
        jugador->mover(direccion);
        tablero->imprimir();
        verificarVictoria();
    }
}

// Cargar un juego guardado desde un archivo
void Juego::cargarJuego(const std::string& archivo) {
    tablero->cargarNivel(archivo);  // Cargar el nivel desde el archivo dado
    tablero->imprimir();            // Imprimir el tablero cargado

    // Continuar el juego después de cargar
    char direccion;
    while (true) {
        std::cout << "Mover (WASD): ";
        std::cin >> direccion;
        jugador->mover(direccion);
        tablero->imprimir();
        verificarVictoria();
    }
}

// Verificar si el jugador ha ganado el nivel
void Juego::verificarVictoria() {
    Nodo* fila = tablero->obtenerNodo(0, 0);
    while (fila) {
        Nodo* actual = fila;
        while (actual) {
            if (actual->simbolo == '$') return;  // Aún hay cajas sin colocar
            actual = actual->derecha;
        }
        fila = fila->abajo;
    }
    std::cout << "¡Nivel completado!" << std::endl;
}
