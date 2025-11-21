//
// Created by Paolo on 17-11-2025.
//

#ifndef ABB_H
#define ABB_H

#include  "Ticket.h"
using namespace std;

class NodoABB {
public:
    Ticket* dato;
    NodoABB* hijoIzq;
    NodoABB* hijoDer;

    NodoABB(Ticket* t) : dato(t), hijoIzq(nullptr), hijoDer(nullptr){}

};

class ABB {
private:
    NodoABB* raiz;

    NodoABB* insertarRec(NodoABB* nodo, Ticket* ticket);
    Ticket* buscarRec(NodoABB* nodo, int id);
    void inOrdenRec(NodoABB* nodo);
    void liberarRec(NodoABB* nodo);

public:
    ABB();
    ~ABB();

    void insertar(Ticket* ticket);

    Ticket* buscar(int id);
    void inOrden();
};



#endif //ABB_H
