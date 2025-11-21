//
// Created by Paolo on 20-11-2025.
//

#ifndef ARBOLENHEBRADO_H
#define ARBOLENHEBRADO_H
#include "Asistente.h"

class NodoEnhebrado {
public:
    int asiento;
    bool ocupado;

    bool hebraIzq;
    NodoEnhebrado* hijoIzq;
    Asistente* dato;
    NodoEnhebrado* hijoDer;
    bool hebraDer;

    NodoEnhebrado(int num) : asiento(num), dato(nullptr), hebraIzq(true), hijoIzq(nullptr), hijoDer(nullptr), hebraDer(true) {}

};

class ArbolEnhebrado {
private:
    NodoEnhebrado* raiz;

    void insertarNodo(int numero);

public:
    ArbolEnhebrado();
    ~ArbolEnhebrado();

    void construirAsientos(int x, int y);

    bool asignarAsiento(int numero, Asistente* a);

    void mostrarInOrden();

    void destruir();
};



#endif //ARBOLENHEBRADO_H
