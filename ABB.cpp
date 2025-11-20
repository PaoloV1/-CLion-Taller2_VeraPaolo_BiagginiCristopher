//
// Created by Paolo on 19-11-2025.
//
#include "ABB.h"
#include <iostream>

using namespace std;

/**
 * @author Paolo Vera
 * Constructor ABB
 */
ABB::ABB() {
    raiz = nullptr;
}

/**
 * @author Paolo Vera
 * Destructor ABB
 */
ABB::~ABB() {
    liberarRec(raiz);
    raiz = nullptr;
}

/**
 * @author Paolo Vera
 * Metodo publico para la insercion de datos en el ABB
 * @param a Persona que se va a ingresar al arbol
 */
void ABB::insertar(Asistente* a) {
    raiz = insertarRec(raiz, a);
}

/**
 * @author Paolo Vera
 * Metodo recursivo y privado para la insercion de datos en el ABB
 * @param nodo
 * @param asistente
 * @return Nodo que se inserto dentro del ABB
 */
NodoABB *ABB::insertarRec(NodoABB *nodo, Asistente* asistente) {
    // Si el nodo actual es nulo, se crea un Nodo
    if (nodo == nullptr) return new NodoABB(asistente);

    // Si el nuevo dato es menor que la raiz se recorre hacia la izquierda
    if (asistente->getId() < nodo->dato->getId()) {
        nodo->hijoIzq = insertarRec(nodo->hijoIzq, asistente);
    }
    // Si el nuevo dato es mayor que la raiz se recorre hacia la derecha
    else if (asistente->getId() > nodo->dato->getId()) {
        nodo->hijoDer = insertarRec(nodo->hijoDer, asistente);
    }
    return nodo;
}

/**
 * @author Paolo Vera
 * Metodo publico para buscar dentro del ABB
 * @param id
 * @return Metodo recursivo para buscar dentro del arbol
 */
Asistente *ABB::buscar(int id) {
    return buscarRec(raiz,id);
}

/**
 * @author Paolo Vera
 * Metodo recursivo y privado para buscar un dato dentro del ABB
 * @param nodo
 * @param id
 * @return
 */
Asistente *ABB::buscarRec(NodoABB *nodo, int id) {
    // Si el nodo no existe
    if (nodo == nullptr) return nullptr;

    // Si el id que se busca es igual a la raiz
    if (id == nodo->dato->getId()) {
        return nodo->dato;
    }
    // Si el id que se busca es menor que la raiz recorremos el arbol por la izquierda
    if (id < nodo->dato->getId()) {
        return buscarRec(nodo->hijoIzq, id);
    }
    // Si el id que se busca es mayor que la raiz recorremos el arbol por la derecha
    return buscarRec(nodo->hijoDer, id);
}

/**
 * @author Paolo Vera
 * Metodo publico para imprimir el arbol In Orden
 */
void ABB::inOrden() {
    inOrdenRec(raiz);
}

/**
 * @author Paolo Vera
 * Metodo privado y recursivo para imprimir el arbol In Orden
 * @param nodo
 */
void ABB::inOrdenRec(NodoABB *nodo) {
    if (nodo == nullptr) return;

    inOrdenRec(nodo->hijoIzq);
    cout << nodo->dato->getId() <<" ";
    inOrdenRec(nodo->hijoDer);
}

/**
 * @author Paolo Vera
 * Metodo Recursivo para eliminar el arbol
 * @param nodo
 */
void ABB::liberarRec(NodoABB *nodo) {

    if (nodo == nullptr) return;
    liberarRec(nodo->hijoIzq);
    liberarRec(nodo->hijoDer);

    delete nodo;
}











