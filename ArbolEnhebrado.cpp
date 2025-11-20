//
// Created by Paolo on 20-11-2025.
//

#include "ArbolEnhebrado.h"

#include <iostream>

ArbolEnhebrado::ArbolEnhebrado() {
    raiz = nullptr;
}

ArbolEnhebrado::~ArbolEnhebrado() {
    destruir();
}

void ArbolEnhebrado::insertarNodo(int numero) {
    NodoEnhebrado* nuevo = new NodoEnhebrado(numero);

    if (raiz == nullptr) {
        raiz = nuevo;
        return;
    }

    NodoEnhebrado* actual = raiz;
    NodoEnhebrado* padre = nullptr;

    while (actual != nullptr) {
        padre = actual;
        if (numero < actual->asiento) {
            if (!actual->hebraIzq) {
                actual = actual->hijoIzq;
            }
            else
                break;
        } else {
            if (!actual->hebraDer) {
                actual = actual->hijoDer;
            }
            else
                break;
        }
    }

    if (numero < padre->asiento) {
        nuevo->hijoIzq = padre->hijoIzq;
        nuevo->hijoDer = padre;
        padre->hebraIzq = false;
        padre->hijoIzq = nuevo;
    } else {
        nuevo->hijoDer = padre->hijoDer;
        nuevo->hijoIzq = padre;
        padre->hebraDer = false;
        padre->hijoDer = nuevo;
    }


}

void ArbolEnhebrado::construirAsientos(int x, int y) {
    for (int i = x; i <= y; i++) {
        insertarNodo(i);
    }
}
bool ArbolEnhebrado::asiganrAsiento(int numero, Asistente *a) {
    NodoEnhebrado* actual = raiz;

    while (actual != nullptr) {
        if (numero == actual->asiento) {
            if (actual->ocupado) return false;

            actual->ocupado = true;
            actual->dato = a;
            return true;
        }

        if (numero < actual->asiento) {
            if (actual->hebraIzq) return false;
            actual = actual->hijoIzq;
        } else {
            if (actual->hebraDer) return false;
            actual = actual->hijoDer;
        }

    }
    return false;
}

void ArbolEnhebrado::mostrarInOrden() {
    if (raiz == nullptr) return;

    NodoEnhebrado* actual = raiz;

    while (!actual->hebraIzq) {
        actual = actual->hijoIzq;
    }

    while (actual != nullptr) {
        cout <<"Asiento" << actual->asiento;
        cout << "- " << (actual->ocupado ? "Ocupado" : "Libre") << endl;

        if (actual->hebraDer) {
            actual = actual->hijoDer;
        } else {
            actual = actual->hijoDer;
            while (actual != nullptr && !actual->hebraIzq) actual = actual->hijoIzq;
        }
    }
}

void ArbolEnhebrado::destruir() {
    NodoEnhebrado* actual = raiz;
    while (actual && !actual->hebraIzq) {
        actual = actual->hijoIzq;
    }
    while (actual != nullptr) {
        NodoEnhebrado* siguiente;

        if (actual->hebraDer) {
            siguiente = actual->hijoDer;
        } else {
            siguiente = actual->hijoDer;
            while (siguiente && !siguiente->hebraIzq) {
                siguiente = siguiente->hijoIzq;
            }
            delete actual;
            actual = siguiente;

        }
        raiz = nullptr;

    }

}






