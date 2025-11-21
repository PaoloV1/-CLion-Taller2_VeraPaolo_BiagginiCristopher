//
// Created by Paolo on 20-11-2025.
//

#include "ArbolEnhebrado.h"

#include <iostream>

/**
 * @author Paolo Vera
 * Metodo constructor Arbol Enhebrado
 */
ArbolEnhebrado::ArbolEnhebrado() {
    raiz = nullptr;
}

/**
 * @author Paolo vera
 * Metodo destructor Arbol Enhebrado
 */
ArbolEnhebrado::~ArbolEnhebrado() {
    destruir();
}

/**
 * @author Paolo Vera
 * Metodo para insertar un nodo dentro del Arbol Enhebrado
 * @param numero de entrada
 */
void ArbolEnhebrado::insertarNodo(int numero) {
    NodoEnhebrado* nuevo = new NodoEnhebrado(numero);

    // Si el arbol esta vacio se ingresa en la raiz
    if (raiz == nullptr) {
        raiz = nuevo;
        return;
    }

    NodoEnhebrado* actual = raiz;
    NodoEnhebrado* padre = nullptr;

    // Si el arbol ya tiene al menos un valor empezamos el recorrido
    while (actual != nullptr) {
        padre = actual;

        // Si el valor que se quiere ingresar es menor que el actual se recorre hacia la izquierda
        if (numero < actual->asiento) {
            if (!actual->hebraIzq) {
                actual = actual->hijoIzq;
            }
            else
                break;

        // Si el valor que se quiere ingresar es mayor que el actual se recorre hacia la derecha
        } else {
            if (!actual->hebraDer) {
                actual = actual->hijoDer;
            }
            else
                break;
        }
    }
    // Insercion como hijo izquierdo
    if (numero < padre->asiento) {
        nuevo->hijoIzq = padre->hijoIzq;
        nuevo->hijoDer = padre;
        padre->hebraIzq = false;
        padre->hijoIzq = nuevo;

    // Insercion como hijo derecho
    } else {
        nuevo->hijoDer = padre->hijoDer;
        nuevo->hijoIzq = padre;
        padre->hebraDer = false;
        padre->hijoDer = nuevo;
    }


}

/**
 * Metodo para construir los asientos del concierto
 * @param x Desde
 * @param y Hasta
 */
void ArbolEnhebrado::construirAsientos(int x, int y) {
    for (int i = x; i <= y; i++) {
        insertarNodo(i);
    }
}

/**
 * @author Paolo Vera
 * Metodo para asignar un asiento a un asistente
 * @param numero de asiento
 * @param a asistente
 * @return
 */
bool ArbolEnhebrado::asignarAsiento(int numero, Asistente *a) {
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

/**
 * @author Paolo Vera
 * Metodo para recorrer el arbol enhebrado in Orden usando hebras
 */
void ArbolEnhebrado::mostrarInOrden() {
    // Si el arbol esta vacio
    if (raiz == nullptr) return;

    NodoEnhebrado* actual = raiz;

    // Mientras que el nodo actual tenga hijo izquierdo recorremos el arbol
    while (!actual->hebraIzq) {
        actual = actual->hijoIzq;
    }
    // Mostramos por pantalla los datos si el asiento esta ocupado o no
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

/**
 * @author Paolo Vera
 * Metodo para eliminar los nodos del Arbol Enhebrado, sera utilizado en el destructor para liberar la memoria
 */
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






