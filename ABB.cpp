#include "ABB.h"
#include <iostream>

using namespace std;

/**
 * Constructor ABB
 */
ABB::ABB() {
    raiz = nullptr;
}

/**
 * Destructor ABB
 */
ABB::~ABB() {
    liberarRec(raiz);
    raiz = nullptr;
}

/**
 * Metodo publico para la insercion de datos en el ABB
 * @param t Ticket que se va a ingresar al arbol
 */
void ABB::insertar(Ticket* t) {
    raiz = insertarRec(raiz,t);
}

/**
 * Metodo recursivo y privado para la insercion de datos en el ABB
 * @param nodo
 * @param ticket
 * @return Nodo que se inserto dentro del ABB
 */
NodoABB *ABB::insertarRec(NodoABB *nodo, Ticket* ticket) {
    // Si el nodo actual es nulo, se crea un Nodo
    if (nodo == nullptr) return new NodoABB(ticket);

    // Si el nuevo dato es menor que la raiz se recorre hacia la izquierda
    if (ticket->getIdTicket() < nodo->dato->getIdTicket()) {
        nodo->hijoIzq = insertarRec(nodo->hijoIzq, ticket);
    }
    // Si el nuevo dato es mayor que la raiz se recorre hacia la derecha
    else if (ticket->getIdTicket() > nodo->dato->getIdTicket()) {
        nodo->hijoDer = insertarRec(nodo->hijoDer, ticket);
    }
    return nodo;
}

/**
 * Metodo publico para buscar dentro del ABB
 * @param id
 * @return Metodo recursivo para buscar dentro del arbol
 */
Ticket *ABB::buscar(int id) {
    return buscarRec(raiz,id);
}

/**
 * Metodo recursivo y privado para buscar un dato dentro del ABB
 * @param nodo
 * @param id
 * @return
 */
Ticket *ABB::buscarRec(NodoABB *nodo, int id) {
    // Si el nodo no existe
    if (nodo == nullptr) return nullptr;

    // Si el id que se busca es igual a la raiz
    if (id == nodo->dato->getIdTicket()) {
        return nodo->dato;
    }
    // Si el id que se busca es menor que la raiz recorremos el arbol por la izquierda
    if (id < nodo->dato->getIdTicket()) {
        return buscarRec(nodo->hijoIzq, id);
    }
    // Si el id que se busca es mayor que la raiz recorremos el arbol por la derecha
    return buscarRec(nodo->hijoDer, id);
}

/**
 * Metodo publico para imprimir el arbol In Orden
 */
void ABB::inOrden() {
    inOrdenRec(raiz);
}

/**
 * Metodo privado y recursivo para imprimir el arbol In Orden
 * @param nodo
 */
void ABB::inOrdenRec(NodoABB *nodo) {
    if (nodo == nullptr) return;

    inOrdenRec(nodo->hijoIzq);
    cout << nodo->dato->getIdTicket() <<" ";
    inOrdenRec(nodo->hijoDer);
}

/**
 * Metodo Recursivo para eliminar el arbol
 * @param nodo
 */
void ABB::liberarRec(NodoABB *nodo) {

    if (nodo == nullptr) return;
    liberarRec(nodo->hijoIzq);
    liberarRec(nodo->hijoDer);

    delete nodo;
}











