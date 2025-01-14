// Tablero.h
#ifndef TABLERO_H
#define TABLERO_H

#include "Nodo.h"
#include <string>

class Tablero {
private:
    Nodo* inicio;           // Puntero al primer nodo del tablero
    int filas, columnas;    // Dimensiones del tablero

public:
    // Constructor del Tablero
    Tablero(int filas, int columnas);

    // Imprimir el tablero en la consola
    void imprimir();

    // Cargar un nivel desde un archivo .txt
    void cargarNivel(std::string archivo);

    // Guardar el nivel actual en un archivo .txt
    void guardarNivel(std::string archivo);

    // Obtener un nodo en una posici�n espec�fica del tablero
    Nodo* obtenerNodo(int fila, int columna);

private:
    // M�todo para construir el tablero utilizando una lista enlazada
    void construirTablero();
};

#endif // TABLERO_H
